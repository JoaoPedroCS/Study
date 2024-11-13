import time
start_time = time.time()

def find_recurring_cycle_length(d):
    remainders = {}
    value = 1
    position = 0

    while value != 0:
        if value in remainders:
            return position - remainders[value]
        remainders[value] = position
        value = (value * 10) % d
        position += 1

    return 0

max_length = 0
d_with_max_cycle = 0

for d in range(2, 1000):
    cycle_length = find_recurring_cycle_length(d)
    if cycle_length > max_length:
        max_length = cycle_length
        d_with_max_cycle = d

print(f"------> R: {d_with_max_cycle} <------")
print(f"-----> {(time.time() - start_time):.5f}S <-----")
