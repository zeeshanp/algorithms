#include <vector>
#include <iostream>

using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix) {
      
       vector<int> ret;
       if (matrix.size() == 0 || matrix[0].size() == 0)
       {
            return ret;
       }
       int L = 0;
       int R = matrix[0].size();
       int T = 0;
       int B = matrix.size();
       int dir = 0;
       
       
       while (L <= R && T <= B)
       {
           if (dir == 0) // right
           {
                for (int i = L; i < R; i++)
                    ret.push_back(matrix[T][i]);
                T++;
           }
           else if (dir == 1) //down
           {
               for (int i = T; i < B; i++)
                    ret.push_back(matrix[i][R]);
               R--;
           }
           else if (dir == 2) // left
           {
               for (int i = R; i > L; i--)
                    ret.push_back(matrix[B][i]);
               B--;
           }
           else if (dir == 3) // up
           {
               for (int i = B; i > T; i--)
                    ret.push_back(matrix[L][i]);
                L++;
           }
           dir = (dir + 1)%4;
        }
        return ret;  
    }

