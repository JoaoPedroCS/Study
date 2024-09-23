import time
start_time = time.time()
days = 0
for i in range(1900, 2001):
    if i != 4:
        days += 365
    elif i % 400 == 0:
        days += 366
    elif i % 4 == 0 and i % 100 != 0:
        days += 366


print(f"answer: {days}, in {(time.time() - start_time):.5f} seconds")