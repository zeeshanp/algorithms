"""Solves problem 17 on projecteuler.net"""


numbers = { 1:"one", 2:"two", 3:"three", 4:"four", 5:"five",
            6:"six", 7:"seven",8:"eight", 9:"nine" }

teens = { 10:'ten',11:"eleven", 12:"twelve", 13:"thirteen", 14:"fourteen",
          15:"fifteen", 16:"sixteen", 17:"seventeen", 18:"eighteen", 
          19:"nineteen" }

tens_conj = { 20:"twenty", 30:"thirty", 40:"forty", 50:"fifty", 60:"sixty",
              70:"seventy", 80:"eighty", 90:"ninety" }



if __name__ == '__main__':
    hundred = len("hundred") 
    and_ = len("and")

    letters = 0
    for hun in range(0,10):
        if hun != 0:
            letters = letters + len(numbers[hun]) + hundred
        for i in range(1,10):
            if hun == 0:
                letters = letters + len(numbers[i])
            else:
                letters = letters + len(numbers[hun]) + hundred + and_ + len(numbers[i])

        for i in range(10, 20):
            if hun == 0:
                letters = letters + len(teens[i])
            else:
                letters = letters + len(numbers[hun]) + hundred + and_ + len(teens[i])

        for i in range(20, 100):
            if hun == 0:
                if i%10 == 0:
                    letters = letters + len(tens_conj[i - (i%10)])
                else:
                    letters = letters + len(tens_conj[i - (i%10)]) + len(numbers[i%10])
            else:
                if i%10 == 0:                 
                    letters = letters + len(numbers[hun]) + hundred + and_ + len(tens_conj[i - (i%10)])
                else:
                    letters = letters + len(numbers[hun]) + hundred + and_ + len(tens_conj[i - (i%10)]) + len(numbers[i%10])
    #add one one thousand
    letters = letters + len("one") + len("thousand")


    print letters


