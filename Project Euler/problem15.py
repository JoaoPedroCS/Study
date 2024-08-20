def factorial_of(x):
    answer = 1
    for i in range(2,x+1):
        answer *= i
    return answer
columns = 20
lines = 20

top = factorial_of(columns + lines)
bottom = factorial_of(columns) * factorial_of(lines)
numberpaths = top/bottom
print(numberpaths)