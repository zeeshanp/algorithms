// given a string and number of rows,
// print the string in row-wise zig-zag fashion
// eg, zig_zag("ABCDEFGH", 2)
// =>   A        C      E        G
//          B       D       F       H
// => ACEGBDFH
// "0123456789", 2
// => 0   2    4    6     8
//      1   3    5     7     9
// n = 3
// => 0         4          8
//      1    3     5    7     9
//         2          6
// n = 4
// => 0           6
//      1       5  7
//        2   4      8
//          3          9

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

string zig_zag(string s, int n) {
    
    vector<string> rows(n, "");
    bool down = false;
    int curr_row = 0;
    for (int i = 0; i < s.length(); i++) {
        rows[curr_row] += s[i];
        if (curr_row == n - 1 || curr_row == 0) {
            down = !down;
        }
        if (down) 
            curr_row++;
        else
            curr_row--;
    }
    string ret;
    for (int i = 0; i < rows.size(); i++) {
        ret += rows[i];
    }
    return ret;
}

int main(int argc, char *argv[]) {

    string s = argv[1];
    int n = atoi(argv[2]);
    cout << zig_zag(s, n) << endl;
    return 0;
}
