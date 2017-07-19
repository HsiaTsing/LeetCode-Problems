#include <iostream>
#include <vector>

using namespace std;

/*
* Given a string, find the length of the longest substring without repeating characters.
*
* Examples:
*   Given "abcabcbb", the answer is "abc", which the length is 3.
*   Given "bbbbb", the answer is "b", with the length of 1.
*   Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> str(256, -1); vector<int> substring;
		int maxlen = 0; int strIdx = 0; int len = 0; int startIdx = 0;
		while (strIdx < s.size()){
			if (str[s[strIdx]] == -1){
				str[s[strIdx]] = 1;
				substring.push_back(s[strIdx]);
				len++; strIdx++;
			}
			else{
				for (int j = 0; j < substring.size(); j++){
					str[substring[j]] = -1;
				}
				substring.clear(); maxlen = fmax(maxlen, len); len = 0; strIdx = ++startIdx;
			}
		}
		return fmax(maxlen, len);
	}
	void test(){
		string s = "abcabcbb";
		cout << lengthOfLongestSubstring(s) << endl;
	}

};