#include <pthread.h>
#include <iostream>
#include <vector>
#include <memory>
#include <unistd.h>

struct ComputeArgs {
    std::vector<int> *nums;
    std::size_t start; // or use begin, end iterator
    std::size_t end;
    int result;
    pthread_mutex_t *lock;
    pthread_cond_t *cond;
    bool* ready;
};

void check_rc(int rc) {
    if (rc) {
        std::cout << "Failed rc:" << rc << std::endl;
        exit(1);
    }
}

/*
 * Lock and Threads basic
 */
void* compute(void *args) {
    auto data = static_cast<ComputeArgs*>(args);
    pthread_t tid = pthread_self();
    pthread_mutex_lock(data->lock);
    std::cout << "Thread:" << tid << " sleep 2 secs before working" << std::endl;
    pthread_mutex_unlock(data->lock);

    sleep(2);
    int res = 0;
    for (int i = data->start; i < data->end; ++i)
        res += (*data->nums)[i];

    data->result = res;

    // just doing it for fun
    return new int(res);
}


int unsynchronized_threads() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    pthread_t t1, t2;
    int rc;

    // pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t lock;
    rc = pthread_mutex_init(&lock, nullptr);
    check_rc(rc);
    ComputeArgs arg1{&nums, 0, 3, 0, &lock, nullptr, nullptr},
        arg2{&nums, 3, 6, 0, &lock, nullptr, nullptr};


    rc = pthread_create(&t1, nullptr, &compute, &arg1);
    check_rc(rc);
    rc = pthread_create(&t2, nullptr, &compute, &arg2);
    check_rc(rc);

    pthread_mutex_lock(&lock);
    std::cout << "waiting for t1 and t2 to join" << std::endl;
    pthread_mutex_unlock(&lock);

    void *for_fun1, *for_fun2;
    // the second arg is a pointer to void*
    pthread_join(t1, &for_fun1);
    pthread_join(t2, &for_fun2);
    // now for_fun stores void* (pointing to some void)

    std::cout << "arg1.result:" << arg1.result << " for_fun1:" << *static_cast<int*>(for_fun1) << std::endl;
    std::cout << "arg2.result:" << arg2.result << " for_fun2:" << *static_cast<int*>(for_fun2) << std::endl;

    delete static_cast<int*>(for_fun1);
    delete static_cast<int*>(for_fun2);

    return 0;
}

/*
 * Condition variable
 */
void* compute_first(void *args) {
    auto data = static_cast<ComputeArgs*>(args);
    pthread_mutex_lock(data->lock);
    std::cout << "compute first half" << std::endl;
    for (int i = data->start; i < data->end; ++i)
        data->result += (*data->nums)[i];
    std::cout << "halfway: " << data->result << std::endl;
    data->start = 3;
    data->end = 6;
    *data->ready = true;
    pthread_cond_signal(data->cond);
    pthread_mutex_unlock(data->lock);
    pthread_exit(nullptr);
}

void *compute_next(void *args) {
    auto data = static_cast<ComputeArgs*>(args);
    pthread_mutex_lock(data->lock);
    while (!*data->ready)
        // sleep till signaled
        pthread_cond_wait(data->cond, data->lock);
    std::cout << "compute second half" << std::endl;
    for (int i = data->start; i < data->end; ++i)
        data->result += (*data->nums)[i];
    std::cout << "final: " << data->result << std::endl;
    pthread_mutex_unlock(data->lock);
    pthread_exit(nullptr);
}


int synchronised_threads() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    pthread_t t1, t2;
    int rc;

    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

    bool ready = false;
    ComputeArgs arg{&nums, 0, 3, 0, &lock, &cond, &ready};

    rc = pthread_create(&t1, nullptr, &compute_first, &arg);
    check_rc(rc);
    rc = pthread_create(&t2, nullptr, &compute_next, &arg);
    check_rc(rc);


    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    std::cout << "final in caller: " << arg.result << std::endl;

    return 0;
}


int main() {
    std::cout << "testing unsynchronized threads" << std::endl;
    std::cout << "******************************" << std::endl;
    unsynchronized_threads();
    std::cout << std::endl;
    std::cout << "testing synchronized threads" << std::endl;
    std::cout << "****************************" << std::endl;
    synchronised_threads();
    return 0;
}