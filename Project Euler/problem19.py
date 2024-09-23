import time
start_time = time.time()


day = 366
yr_leap = False
sundays_on_first = 0

for year in range(1901, 2001):
    period = year - 1901

    if year % 4 != 0:
        yr_leap = False
    elif year % 4 == 0 and year % 100 != 0:
        yr_leap = True
    elif year % 400 == 0:
        yr_leap = True


    for l in range(1, 13):
        if l == 1 or l == 3 or l == 5 or l == 7 or l == 8 or l == 10 or l == 12:
            if day % 7 == 0:
                sundays_on_first += 1
            day += 31
        elif l == 4 or l == 6 or l == 9 or l == 11:
            if day % 7 == 0:
                sundays_on_first += 1
            day += 30
        elif l == 2:
            if day % 7 == 0:
                sundays_on_first += 1
            if yr_leap:
                day += 29
            else:
                day += 28
            


print(f"answer: {sundays_on_first}, in {(time.time() - start_time):.5f} seconds")