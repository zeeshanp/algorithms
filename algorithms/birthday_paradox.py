""" python simulation of birthday paradox
    Assuming 23 people in the room, what is the 
    probability two of them have the same birthday? """

from random import randint

n = 23
days = 365

numShared = 0.0
numDiff = 0.0
j = 0
while(True):
    j = j + 1
    birthdays = set([])
    for i in range(0, n):
        birthdays.add(randint(0, days))

    if n > len(birthdays):
        numShared = numShared + 1
    else:
        numDiff = numDiff + 1

    percent = numShared/(numShared + numDiff)
    if (j%100 == 0):
        print "iteration #" + str(j) + ": percentage: " + str(percent)
 
