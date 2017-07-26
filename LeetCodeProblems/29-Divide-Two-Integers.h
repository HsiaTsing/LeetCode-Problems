#include <iostream>

using namespace std;

/*
* Divide two integers without using multiplication, division and mod operator.
*
* If it is overflow, return MAX_INT.
**/


class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
			return INT_MAX;

		long long fdividend = labs(dividend);
		long long fdivisor = labs(divisor);

		int res = 0;
		while (fdivisor <= fdividend){
			long long temp = fdivisor, multiple = 1;
			while ((temp << 1) <= fdividend){
				temp <<= 1;
				multiple <<= 1;
			}
			fdividend -= temp;
			res += multiple;
		}

		if ((dividend >= 0 && divisor > 0) || (dividend < 0 && divisor < 0))
			return res;
		else
			return -res;
	}
	void test(){
		int diviend = 500, divisor = 25;
		cout << divide(diviend, divisor) << endl;
	}
};