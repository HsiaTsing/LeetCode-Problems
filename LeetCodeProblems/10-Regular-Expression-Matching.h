#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
* Implement regular expression matching with support for '.' and '*'.
*
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
*
* The matching should cover the entire input string (not partial).
*
* The function prototype should be:
*
* bool isMatch(const char *s, const char *p)
*
* Some examples:
*   isMatch("aa","a") ? false
*   isMatch("aa","aa") ? true
*   isMatch("aaa","aa") ? false
*   isMatch("aa", "a*") ? true
*   isMatch("aa", ".*") ? true
*   isMatch("ab", ".*") ? true
*   isMatch("aab", "c*a*b") ? true
*/


class Solution {
public:
	bool isMatch(string s, string p) {
		/**
		* f[i][j]: if s[0..i-1] matches p[0..j-1]
		* if p[j - 1] != '*'
		*      f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] = '.'
		* if p[j - 1] == '*', denote p[j - 2] with x
		*      f[i][j] is true iff any of the following is true
		*      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
		*      2) "x*" repeats >= 1 times and matches "x*x": (s[i - 1] == x || p[i - 2] = '.'�� && f[i - 1][j]
		*/

		int m = s.size(), n = p.size();
		vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));

		f[0][0] = true; // empty matches empty
		for (int i = 1; i <= m; i++){
			f[i][0] = false; // empty don't match non-empty
		}

		// p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
		for (int j = 1; j <= n; j++){
			f[0][j] = j > 1 && p[j - 1] == '*' && f[0][j - 2];
		}
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				if (p[j - 1] != '*'){
					f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				}
				else{
					f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && f[i - 1][j];
				}
			}
		}

		return f[m][n];
	}

	void test(){

		string s = "aab", p = "c*a*b";
		cout << isMatch(s, p) << endl;
	}

};