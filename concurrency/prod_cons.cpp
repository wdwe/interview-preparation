#include <pthread.h>
#include <vector>
#include <string>
#include <iostream>
#include <unistd.h>

struct ThreadData {
    std::vector<int> buffer;
    pthread_cond_t *con_cond;
    pthread_cond_t *prod_cond;
    pthread_mutex_t *lock;
    int num_item;
    int remaining;
};

void* consume(void* arg) {
    auto* data = static_cast<ThreadData*> (arg);
    int item;
    pthread_t tid = pthread_self();
    while (true) {
        pthread_mutex_lock(data->lock);
        while (data->num_item == 0) {
            if (!data->remaining) {
                pthread_cond_signal(data->con_cond);
                pthread_mutex_unlock(data->lock);
                pthread_exit(nullptr);
            }
            pthread_cond_wait(data->con_cond, data->lock);
        }
        item = data->buffer[--data->num_item];
        pthread_cond_signal(data->prod_cond);
        pthread_mutex_unlock(data->lock);
        // do something with the item
        sleep(1);
        std::string s = "thread:" + std::to_string(tid) + " item:" + std::to_string(item);
        std::cout << s << std::endl;
    }
}

void* produce(void* arg) {
    auto data = static_cast<ThreadData*>(arg);
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(data->lock);
        while (data->num_item == data->buffer.size()) {
            pthread_cond_wait(data->prod_cond, data->lock);
        }
        data->buffer[data->num_item++] = i;
        pthread_cond_signal(data->con_cond);
        pthread_mutex_unlock(data->lock);
    }
    pthread_mutex_lock(data->lock);
    data->remaining--;
    pthread_mutex_unlock(data->lock);
    pthread_exit(nullptr);
}


int main() {
    int num_prod = 10, num_cons = 10;
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t prod_cond = PTHREAD_COND_INITIALIZER, con_cond = PTHREAD_COND_INITIALIZER;
    ThreadData data = ThreadData{std::vector<int>(10, 0), &con_cond, &prod_cond, &lock, 0, num_prod};

    std::vector<pthread_t> prod_threads, con_threads;
    for (int i = 0; i < num_prod; ++i) {
        pthread_t tid;
        pthread_create(&tid, nullptr, produce, &data);
        prod_threads.push_back(tid);
    }

    for (int i = 0; i < num_cons; ++i) {
        pthread_t tid;
        pthread_create(&tid, nullptr, consume, &data);
        con_threads.push_back(tid);
    }

    for (pthread_t tid: prod_threads)
        pthread_join(tid, nullptr);
    for (pthread_t tid: con_threads)
        pthread_join(tid, nullptr);

    return 0;
}