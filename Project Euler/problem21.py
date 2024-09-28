import time
import math
start_time = time.time()

amount = []
def factors(n):
    factors = [1]
    for i in range(2, math.floor(math.sqrt(n)) + 1):
        if n % i == 0:
            factors.append(i)
            pair = n / i
            factors.append(pair)
    return int(sum(factors))

for i in range(1, 10000):
    x = factors(i)
    if factors(x) == i and i != factors(i):
        amount.append(i)

print(f"answer: {sum(amount)}, in {(time.time() - start_time):.5f} seconds")