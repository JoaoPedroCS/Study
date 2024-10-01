import random
soma = 0
z = 1000000
for i in range(1, z):
    x = random.randint(1, 100)
    if 1<=x<=60:
        y = random.randint(1,100)
        if y <= 70:
            v = 1
        elif y > 70:
            v = 0
    elif 61 <= x <= 90:
        y = random.randint(1, 100)
        if y <= 35:
            v = 1
        elif y > 35:
            v = 0
    elif 91 <= x <= 100:
        y = random.randint(1, 10000)
        if y <= 2625:
            v = 1
        elif y > 2625:
            v = 0
    
    soma += v
s = soma/z
print(s*100)