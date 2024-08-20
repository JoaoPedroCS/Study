import math
def num_factors(x):
    factors = 0
    for i in range(1, int(x**0.5)+1):
        if x % i == 0:
            if i == x/i:
                factors += 1
            elif i != x/i:
                factors +=2

    return factors

n = 1
tn = 1
lista = [1]
while num_factors(tn) < 500:
    n += 1
    tn += n
    lista.append(tn)

print(tn)