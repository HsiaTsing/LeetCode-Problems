#include <iostream>
#include <string>

using namespace std;

/*
* Implement atoi to convert a string to an integer.
*
* Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask 
* yourself what are the possible input cases.
*
* Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible 
* to gather all the input requirements up front.
*
* Update (2015-02-10):
* The signature of the C++ function had been updated. If you still see your function signature accepts a const char * 
* argument, please click the reload button  to reset your code definition.
*
* Requirements for atoi:
* The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
* Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits 
* as possible, and interprets them as a numerical value.
*
* The string can contain additional characters after those that form the integral number, which are ignored and have no 
* effect on the behavior of this function.
*
* If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence 
* exists because either str is empty or it contains only whitespace characters, no conversion is performed.
*
* If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of 
* representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/


class Solution {
public:
	int myAtoi(string str) {
		char c;
		int startIdx = str.find_first_not_of(" ");
		if (startIdx < 0)
			return 0;
		if (!((c = str[startIdx]) >= '0' && c <= '9') && c != '+' && c != '-')
			return 0;

		long long x = 0;

		int flag = 1;
		if (c == '+')
			flag = 1;
		else if (c == '-')
			flag = -1;
		else
			x = c - '0';

		int idx = startIdx + 1;
		while ((c = str[idx++]) >= '0' && c <= '9')
			x = x * 10 + c - '0';

		x *= flag;

		if ((idx - startIdx - 1) > 11 && flag == 1)
			return INT_MAX;
		if ((idx - startIdx - 1) > 11 && flag == -1)
			return INT_MIN;
		if (x > INT_MAX)
			return INT_MAX;
		if (x < INT_MIN)
			return INT_MIN;

		return x;
	}

	void test(){

		string s = "-123456";
		cout << myAtoi(s) << endl;
	}

};