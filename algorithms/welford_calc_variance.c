#include "../libft.h"

#define MIN_SAMPLES 2 

/*
Gets the variance from wf, with Bessel correction
@param wf the struct with all the samples
@return 0 if n <= 1, in either case the variance as a float
*/
double	welford_calc_variance(t_welford *wf)
{
	double variance;

	variance = 0.0;
	if (wf->n_samples < MIN_SAMPLES)
		return (variance);
	variance = wf->sqrd_mean / (wf->n_samples - 1);
	return (variance);
}
