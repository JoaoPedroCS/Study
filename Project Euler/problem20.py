import time
start_time = time.time()

product = 1
for i in range(1, 101):
    product *= i

product = sum([int(i) for i in str(product)])

print(f"answer: {product}, in {(time.time() - start_time):.5f} seconds")