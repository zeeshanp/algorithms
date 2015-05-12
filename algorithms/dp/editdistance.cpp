
#include <iostream>
#include <string>

using namespace std;


// edit distance between strings using dynamic programming

int smallest(int x, int y, int z)
{
    return min(min(x, y), z);
}

int diff(int a, int b)
{
	return (a == b) ? 0 : 1;
}


int editDistance(string& a, string& b)
{
	int m = a.length();
	int n = b.length();

	int subproblems[m][n];

	// base cases

	for (int i = 0; i < m; i++)
	{
		subproblems[i][0] = i;
	}

	for (int j = 0; j < n; j++)
	{
		subproblems[0][j] = j;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			subproblems[i][j] = smallest(subproblems[i - 1][j] + 1, subproblems[i][j - 1] + 1, subproblems[i - 1][j - 1] + diff(a[i],b[j]) );
		}
	}

	return subproblems[m - 1][n - 1];
}


int main()
{
	string a = "Snowy";
	string b = "Sunny";
	cout << editDistance(a, b) << endl;
}