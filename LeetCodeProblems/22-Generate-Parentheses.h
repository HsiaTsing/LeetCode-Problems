#include <iostream>
#include <vector>
#include <string>


using namespace std;

/*
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
* 
* For example, given n = 3, a solution set is:
*
* [
* "((()))",
* "(()())",
* "(())()",
* "()(())",
* "()()()"
* ]
**/


class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		addPar(res, "", n, 0);
		return res;
	}

	void addPar(vector<string> &v, string s, int n, int m){
		if (n == 0 && m == 0){
			v.push_back(s);
			return;
		}

		if (n > 0) addPar(v, s + "(", n - 1, m + 1);
		if (m > 0) addPar(v, s + ")", n, m - 1);
	}

	void test(){
		int n = 3;
		vector<string> res = generateParenthesis(n);
		cout << "[" << endl;
		for (int i = 0; i < res.size(); i++)
		{
			cout << "\"" << res[i] << "\"";
			if (i == res.size() - 1)
				cout << endl;
			else
				cout << "," << endl;
		}
		cout << "]" << endl;
	}

};