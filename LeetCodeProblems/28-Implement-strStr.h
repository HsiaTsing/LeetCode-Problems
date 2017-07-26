#include <iostream>
#include <vector>


using namespace std;

/*
* Implement strStr().

* Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
**/


class Solution {
public:
	int strStr(string haystack, string needle) {
		int len = haystack.size() - needle.size();
		for (int i = 0; i <= len; i++){
			if (haystack.substr(i, needle.length()) == needle){
				return i;
			}
		}
		return -1;
	}
	void test(){
		string h = "abcd", n = "bcd";
		cout << strStr(h, n) << endl;
	}
};