#include "karatsuba.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int num1, num2;
	cout <<"Number 1 : ";
	cin >> num1;
	cout <<"Number 2 : ";
	cin >> num2;
	int ans = karatsuba(num1, num2);
	cout <<"Answer = "<<ans<<endl;
	// cout <<getOrderOfNumber(1)<<endl;
	return 0;
}