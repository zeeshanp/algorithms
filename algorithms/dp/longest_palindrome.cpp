#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

string longest_palindrome_sub(string s) {

    int n = s.length();

    vector<vector<int> > sub_problems(n, vector<int>(n));

    // back_ptrs holds (i, j) pairs for backtracking
    vector<vector<pair<int, int> > back_ptrs(n, vector<pair<int, int> >(n));

    // L[i, j] = f( L[i+1,j-1], L[i, j-1], L[i+1, j] )
    //   0 1 2 3 4 5 
    // 0 1         x
    // 1   1
    // 2     1
    // 3       1    
    // 4         1 
    // 5           1

    // base cases, i == j.
    for (int i = 0; i < n; i++) {
        sub_problems[i][i] = 1;
    }

    for (int i = n - 1; i >= 0; i--) { 
        for (int j = i + 1; j < n; j++) {
        
            if (s[i] == s[j]) {
                if (i + 1 == j) {
                    sub_problems[i][j] = 2;
                } else {
                    sub_problems[i][j] = 2 + sub_problems[i+1][j-1];
                    back_ptrs[i][j] = make_pair(i + 1, j - 1);
                }
            } else {
                if (sub_problems[i+1][j] > sub_problems[i][j - 1]) {
                    sub_problems[i][j] = sub_problems[i+1][j];
                    back_ptrs[i][j] = make_pair(i+1, j);
                } else {
                    sub_problems[i][j] = sub_problems[i][j - 1];
                    back_ptrs[i][j] = make_pair(i, j-1);
                }
            }
        
        }
    }
    cout << sub_problems[0][n - 1] << endl;

    // back track through.
    int ii = back_ptrs[0][n - 1].first;
    int jj = back_ptrs[0][n - 1].second;
  
    return "";
}

int main() {

    cout << longest_palindrome_sub("turboventilator") << endl;
    return 0;
}
