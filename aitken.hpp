

// The transformation is especially good when sn has the form
// sn = S + a * p^n;
// It is particularly useful to accelerate series of partial 
// sums. e.g. Logarithmic series log(1+x) = x - x^2/2 + x^3/3..
// This sum converges quite slowly with n. However, recursively
// applying aitkens transformation on the sequences converges
// this sum very quickly

// compute aitken transformation of a series sn, of length n
// into another series tn which is of length n - 2
void aitken (const double* sn, double* tn, int n);


// Applies aitken iteration n/2 times to initial seq sn
// and returns single extrapolated value which can often hit
// the converged value much faster than sn.
// seq sn is overwritten, tn is scratch space
double aitkenExtrapolate(double* sn, double* tn, int n );
