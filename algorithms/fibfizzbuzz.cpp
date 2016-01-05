#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// primality test, in O(root(N)) time.
bool isPrime(int n) {

    if (n <= 1) {
        return false;
    }

    int root = sqrt(n);

    for (int i = 1; i < root; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Helper functions for pretty printing

void printFib(int n, string val) {
    cout << "F_" << n << ": " << val << endl;
}

void printFib(int n, int val) {
    cout << "F_" << n << ": " << val << endl;
}

// Assumes that the fibonacci numbers
// are 0 indexed and follow the following
// sequence:
// 0, 1, 1, 2, 3, 5, 8...
void fibFizzBuzz(int n) {
    
    if (n < 0) 
        return;

    if (n == 0) {
        printFib(0, 0);
        return;
    }

    if (n == 1) {
        printFib(0, 0);
        printFib(1, 1);
        return;
    }

    printFib(0, 0);
    printFib(1, 1);
  
    int f1 = 0;
    int f2 = 1;
    int fn;

    for (int i = 2; i <= n; i++) {
      
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;        

        if (fn % 3 == 0) 
            printFib(i, "Buzz");
        else if (fn % 5 == 0)
            printFib(i, "Fizz");
        else if (isPrime(fn))
            printFib(i, "BuzzFizz");
        else
            printFib(i, fn);
    }

}

// tested with clang-600.0.57 on OS X 10.11.1
 
int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        cout << "Usage: ./fibfizzbuzz <n>" << endl;
        return 0;
    }    

    int n = atoi(argv[1]);    
    fibFizzBuzz(n);

}
