#include <iostream>

using namespace std;

/*
* Determine whether an integer is a palindrome. Do this without extra space.

* Some hints:
* Could negative integers be palindromes? (ie, -1)

* If you are thinking of converting the integer to string, note the restriction of using extra space.

* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
* you know that the reversed integer might overflow. How would you handle such case?

* There is a more generic way of solving this problem.
*/


class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		long long invx = 0;
		int orgx = x;

		while (x != 0){
			invx = invx * 10 + x % 10;
			x = x / 10;
		}

		return orgx == invx;
	}

	void test(){

		int x = 12321;
		cout << isPalindrome(x) << endl;
	}

};