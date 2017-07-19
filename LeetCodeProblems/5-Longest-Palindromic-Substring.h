#include <iostream>
#include <string>

using namespace std;

/*
* Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
*
* Example:
*   Input: "babad"
*   Output: "bab"
*   Note: "aba" is also a valid answer.
*
* Example:
*   Input: "cbbd"
*   Output: "bb"
*/


class Solution {
public:
	string longestPalindrome(string s) {
		int maxLen = 0; int startIdx = 0;

		for (int i = 0; i < s.size(); i++){
			int k = i - 1; int l = i + 1;
			while (k >= 0 && l < s.size() && s[k] == s[l]){
				k--; l++;
			}
			int len = l - k - 1;
			if (maxLen < len){
				maxLen = len;
				startIdx = k + 1;
			}
		}

		for (int i = 0; i < s.size(); i++){
			int k = i; int l = i + 1;
			while (k >= 0 && l < s.size() && s[k] == s[l]){
				k--; l++;
			}
			int len = l - k - 1;
			if (maxLen < len){
				maxLen = len;
				startIdx = k + 1;
			}
		}

		return s.substr(startIdx, maxLen);
	}

	void test(){

		string s = "babad";
		cout << longestPalindrome(s) << endl;
	}

};