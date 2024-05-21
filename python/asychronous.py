"""
credit: https://realpython.com/async-io-python/
"""
import asyncio
import random


# Simple async pattern
async def func_1(name):
    print(f"entered func_1({name})")
    await asyncio.sleep(2)
    random_num = random.randint(1, 10)
    print(f"in func_1({name}) - {random_num}")
    return random_num


async def simple_async():
    # res = []
    # for i in range(5):
    #     res.append(await func_1(str(i)))
    res = await asyncio.gather(*(func_1(f"{i}") for i in range(5)))
    return res


# Producer and consumer
async def produce(name, q):
    for i in range(5):
        print(f"in {name}, putting {i}")
        await q.put(f"{name}: {i}")
        await asyncio.sleep(random.randint(1, 5))


async def consume(name, q: asyncio.Queue):
    while True:
        content = await q.get()
        print(f"in {name}, received '{content}'")
        await asyncio.sleep(random.randint(1, 3))
        q.task_done()


async def producer_consumer(p, c):
    q = asyncio.Queue()
    producers = [asyncio.create_task(produce(f"producer_{i}", q)) for i in range(p)]
    consumers = [asyncio.create_task(consume(f"consumer_{i}", q)) for i in range(c)]
    await asyncio.gather(*producers)  # wait till all producers finish
    await q.join()  # wait till all consumers finished their current tasks
    # now that producers stopped producing and all tasks are finished by the consumers
    # we can cancel consumers
    for cons in consumers:
        cons.cancel()
    print("finished all items")


if __name__ == "__main__":
    res = asyncio.run(simple_async())
    print(res)

    asyncio.run(producer_consumer(p=10, c=5))
