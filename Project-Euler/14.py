record = 0
norecord = 0
for i in range(1, 1000001):
    n = i
    terms = 1

    while n != 1:
        terms +=1
        if n % 2 == 0:
            n = n/2
        elif n % 2 != 0:
            n = (3*n) + 1
    if record < terms:
        record = terms
        norecord = i

print(record, norecord)