#include <iostream>
#include <math.h>

using namespace std;


// find the minimum square sum of n,
// ie. 12 = 2^2 + 2^2 + 2^2 
// NOT 12 = 3^2 + 1^2 + 1^2 + 1^2
// greedy doesn't work, so use dynamic programming here.
// let mss(n) = # of squares in mss of n.
// mss(n) = 1 + min [ mss(n - 1), mss(n - 4) , mss(n - 9), ... ] 
// mss(n) = 1 + min [ mss(n - x^2) for 0 < x < sqrt(n) ]

bool isSquare(int n) { return sqrt(n) == floor(sqrt(n)); }

void findMinSquares(int n) {

    int *subproblems = new int[n + 1];
    int *prev = new int[n + 1];

    // base cases.
    subproblems[0] = 0;
    subproblems[1] = 1;
    subproblems[2] = 2;
    prev[0] = 0;
    prev[1] = 0;
    prev[2] = 1;

    for (int i = 2; i <= n; i++) {
        // find min
        int min = INT_MAX;
        for (int j = 1; j <= sqrt(i); j++) {
            if (subproblems[i - j*j] < min) {
                min = subproblems[i-j*j];
                prev[i] = i - j*j;
            }
        }
        subproblems[i] = 1 + min;
    }
    
    // backtracking.
    int pos = n;
    while ( pos != 0 ) {
        int curr = pos;
        int back = prev[pos];
        cout << sqrt(curr - back) << "^2 + ";
        pos = back;
    }
    cout << "0" << endl;
}


int main() {
    for (;;) {
        int i;
        cout << "Enter a number: ";
        cin >> i;
        findMinSquares(i);
    }
}
