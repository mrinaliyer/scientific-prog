#include "aitken.hpp"
#include <iostream>
#include <math.h>
#include <iomanip>

// Evalute log (1+x) using a series expansion formula
// x^1/1 - x^2/2 + x^3/3 - x^4/4 ...
// Such an expansion is valid for |x| < 1

double partialSum (const double x, const int n) {

	double sum = 0;
	double prod = 1;
	for(int i = 1; i < n + 1; ++i) {
		prod *= x;
		int sign = (i % 2 == 0) ? 1 : -1;
		sum = sum + sign * prod / i;
	}

	return sum;
}

// n = number of partial sums that are iterated upon
// returns extrapolatedSum from these n partial sums
// expectation is that extrapolatedSum can hit desired accuracy
// in far fewer steps
double extrapolatedSum (const double x, const int n) {

	double *s1, *s2, sum = 0, prod = 1;

	s1 = new double[n];
	s2 = new double[n-2];

	for (int i = 0; i < n + 1; ++i) {
		prod *= x;
		int sign = (i%2 == 0) ? 1 : -1;
		sum += sign * prod / i;
		s1[i] = sum;
	}

	sum = aitkenExtrapolate(s1, s2, n);

	delete [] s1;
	delete [] s2;
	return sum;
}

int main (int argc, char ** argv) {

	const int N = 10, n = 13;

	int i;

	double xlist[N+1], val1, val2, val3;

	xlist[N] = 1.25;
	for (int i = 0; i < N; ++i) {
		xlist[i] = 1.0 * i / (N - 1);
	}

	std::cout<<"\tx \tPartial sum \tExtrapolated Sum \tTrue Value"<<std::endl;
	
	std::cout<<std::fixed;
	std::cout<<std::setprecision(3);

	for (int i = 0; i < N + 1; ++i) {
		val1 = partialSum(xlist[i], n);
		val2 = extrapolatedSum( xlist[i], n);
		val3 = log(1 + xlist[i]);
		std::cout<<"\t"<<xlist[i]<<"\t"<<val1<<"\t"
				 <<"\t"<<val2<<"\t\t\t"<<val3<<std::endl;
	}
}
