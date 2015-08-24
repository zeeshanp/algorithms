#include <iostream>
#include <string>
#include <algorithm>
#include <unistd.h>

using namespace std;

string LIS(const string a) {
    int len = a.length();

    // holds answers to subproblems
    int* subproblems = new int[len];
    int* prev = new int[len];

    for (int i = 0; i < len; i++) {
       
        // find max(subproblems(u) + 1) for a[u] < a[i] and u < i
        int max = 0;
        int max_index = -1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                int potential_max = subproblems[j];
                int potential_index = j;
                if (potential_max > max) {
                    max = potential_max;
                    max_index = j;
                }
            }    
        }
        subproblems[i] = max + 1;
        prev[i] = max_index;
    }
    

    // get max answer and its index.
    
    int max = -1;
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (subproblems[i] > max) {
            max = subproblems[i];
            index = i;
        }
    }

    string ans;
    while (index != -1) {
        ans += a[index];
        index = prev[index];
    } 
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    cout << "Enter a sequence of numbers: ";
    string a;
    cin >> a;

    cout << LIS(a) << endl;

}
