#include "aitken.hpp"
#include <algorithm>
#include <iostream>

double transform (double s, double s_next, double s_next2) {

	double t = s - (s_next - s) * (s_next - s) / 
	    	  (s_next2 - 2 * s_next + s);

	return t;
}

void aitken(double *sn, double *tn, int n) {

	for (int i = 0; i < n - 2; ++i) {
		tn[i] = transform(sn[i], sn[i+1], sn[i+2]); 
	}
}

double aitkenExtrapolate(double* sn, double* scratch, int n){

	while (n > 2) {
		aitken(sn, scratch, n);
		std::swap(sn, scratch);
		n = n - 2;
	}

	return (n%2 == 1) ? scratch[0] : scratch[1];
}
