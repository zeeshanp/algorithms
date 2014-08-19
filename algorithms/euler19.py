"""Solves project Euler #19"""


#0 - mon, 1 - tues, 2 - weds, 3 - thurs, 4 - fri, 5 - sat, 6 - sun

months = [31,28,31,30,31,30,31,31, 30,31,30,31]


if __name__ == '__main__':
    num = 0
    date = 1
    day_of_week = 1
    leap = False
    #Jan 1st, 1901 was a tuesday.
    for year in range(1901, 2001):
        if (year%100 == 0 and year%400 == 0):
            leap = True
        elif (year%100 == 0 and year%400 != 0):
            leap = False
        else:
            leap = (year % 4 == 0)

        for m in range(0,12):
            if leap == True and m == 1:
                curr = 29
            else:
                curr = months[m]
            for i in range(1, curr+1):
                date = date + 1
                day_of_week = (day_of_week + 1)%7
                if day_of_week == 6 and date == 1:
                    num = num + 1
            date = 0

    print num
