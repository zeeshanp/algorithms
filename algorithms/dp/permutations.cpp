// compute all permutations of a string

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> insertCharAtEveryPos(string a, char b)
{
	vector<string> ret;


	for (int i = 0; i <= a.length(); i++)
	{
		string next = a.substr(0, i) + b + a.substr(i);
		ret.push_back(next);
	}
	return ret;
}

vector<string> permute(string a)
{

	vector<string> ret;
	
	// base cases
	if (a.length() == 0)
	{
		return ret;
	}

	if (a.length() == 1)
	{
		ret.push_back(a);
		return ret;
	}

	if (a.length() == 2)
	{
		ret.push_back(a);
		reverse(a.begin(), a.end());
		ret.push_back(a);
		return ret;
	}	


	char toInsert = a[a.length() - 1];
	
	vector<string> sub = permute(a.substr(0, a.length() - 1));
	
	for (int i = 0; i < sub.size(); i++)
	{
		vector<string> z = insertCharAtEveryPos(sub[i], toInsert);
		ret.insert(ret.begin(), z.begin(), z.end());
	}

	return ret;

}


int main()
{

	string a = "abcd";
	
	vector<string> p = permute(a);
	for (int i = 0; i < p.size(); i++)
	{
		cout << p[i] << endl;
	}
}


