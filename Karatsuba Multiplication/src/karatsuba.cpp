#include "karatsuba.hpp"

using namespace std;

int karatsuba(int X, int Y) {
	int digits = getOrderOfNumber(min(X, Y));

	// base condition
	if (digits == 1) {
		return X * Y;
	}

	int bm = pow(static_cast<double>(10), digits/2);

	int a = X / bm;
	int b = X % bm;

	int c = Y / bm;
	int d = Y % bm;

	int r1 = karatsuba(a, c);
	int r2 = karatsuba(b, d);
	int r3 = karatsuba((a+b), (c+d)) - r1 - r2;

	return (pow(static_cast<double>(10), digits) * r1) + r2 + (pow(static_cast<double>(10), (digits/2)) * r3);
} 

int getOrderOfNumber(int number) {
	number = number == 0 ? 1: number;
	return floor(log10(number)) + 1;
}