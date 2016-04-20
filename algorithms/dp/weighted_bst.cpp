#include <iostream>
#include <vector>

using namespace std;

// compiled using C++11

int min_int(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

// precompute all the subsums of the vector.
// for i < j, s[i][j] is the sum of all elems from v[i] to v[j]
// for i > j, s[i][j] = 0
// we can compute this in O(n^2) using greedy fashion:
// s[i][j] = w_j + s[i][j-1]
vector<vector<int>> compute_sums(vector<int> v) {

    int n = v.size();
    vector<vector<int>> sums(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        sums[i][i] = v[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sums[i][j] = sums[i][j - 1] + v[j];
        }
    }
    return sums;
}


// given a set of nodes k_i with weights W_i
// construct a binary search tree that minimizes the function:
// cost = sum( w_i * depth(k_i) )
// think of w_i's as "search probabilities, so this algorithm
// wants to put keys that are searched for more at shallow spots.

// vals - a sorted list of elements in the final bst
// weights - weights of vals

int smallest_bst(vector<int> vals, vector<int> weights) {
    
    int n = vals.size();
    vector<vector<int>> c(n, vector<int>(n)); 

    // c(i, j) = best bst with nodes i to j
    // c(i, j) = min(c(i, l-1) + c(l+1, j)) + W[i, j]
    //           k in [i, j] and W[i, j] is the total sum
    //           of the weights from i to j. adding in this sum
    //           for each subproblem accounts for the depth. For example,
    //           if nodes x..y are on the nth level, they will be added
    //           n times through the recursion.
    // the answer is in c(0, n-1) 
    // base cases:
    //      c(i, i) = w_i

    for (int i = 0; i < n; i++) {
        c[i][i] = weights[i]; 
    }

    // precompute the weight sums to save time
    vector<vector<int>> sums = compute_sums(weights);


    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            int min = 100000;
            if (j == i + 1) {
                min = min_int(c[i][i], c[j][j]);
            } else {
                for (int k = i + 1; k < j; k++) {
                    int p = c[i][k - 1] + c[k + 1][j];
                    if (p < min) {
                        min = p;
                    }
                }
            }
            // add weights to account for depth
            min += sums[i][j];
            c[i][j] = min;
        }
        
    }


    return c[0][n - 1];
}

int main() {

    vector<int> vals {1, 2, 3, 4};
    vector<int> weights {1, 10, 8, 9};
    
    cout << smallest_bst(vals, weights) << endl;
}
