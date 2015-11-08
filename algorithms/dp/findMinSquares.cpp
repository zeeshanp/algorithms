#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>
#include <vector>

using namespace std;


// find the minimum square sum of n,
// ie. 12 = 2^2 + 2^2 + 2^2 
// NOT 12 = 3^2 + 1^2 + 1^2 + 1^2
// greedy doesn't work, so use dynamic programming here.
// let mss(n) = # of squares in mss of n.
// mss(n) = 1 + min [ mss(n - 1), mss(n - 4) , mss(n - 9), ... ] 
// mss(n) = 1 + min [ mss(n - x^2) for 0 < x < sqrt(n) ]

bool isSquare(int n) { return sqrt(n) == floor(sqrt(n)); }

vector<int> findMinSquares(int n) {

    vector<int> subproblems(n + 1, 0);
    vector<int> prev(n + 1, 0);

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
    vector<int> res;
    while ( pos != 0 ) {
        int curr = pos;
        int back = prev[pos];
        res.push_back(sqrt(curr - back));
        pos = back;
    }
    return res;
}


int main(int argc, char *argv[]) {
    
    if (argc != 2) { 
        return 0; 
    }

    int in = atoi(argv[1]);
    vector<int> res = findMinSquares(in);

    cout << in << " = ";    
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "^2";
        if (i != res.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl;

}



