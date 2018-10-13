#include "aitken.hpp"
#include <iostream>
#include <iomanip>
#include "TimeStamp.hh"

// fill with partial sums of form 4( 1 - 1/3 + 1/5 -1/7 ..)
void leibnitz (double * seq, int len) {

	for (int i = 0; i < len; ++i) {

		int sign;
		if (i == 0) {
			seq[i] = 4.0;
		} else if (i %2 == 1) {
			seq[i] = seq[i-1] - 4.0/(2.0*i + 1);
		} else {
			seq[i] = seq[i-1] + 4.0/(2.0*i +1);
		}
	}

}


int main () {

	int n = 13;
	double * seq = new double[n];
	double * scratch = new double[n-2];

	TimeStamp t;
	t.tic();
	leibnitz(seq, n);
	double cycles = t.toc();

	std::cout<<"Took "<<cycles<<" cycles for "<<n<<" steps"<<std::endl;

	std::cout<<std::fixed;
	std::cout<<std::setprecision(7);
	double extrapolatedPi = aitkenExtrapolate(seq, scratch, n);
	std::cout<<"\t"<<"ExtrapolatedPi "<<extrapolatedPi<<std::endl;

	delete [] seq;
	delete [] scratch;
}
