#include "../libft.h"

/*
Gets the stddev from wf
@param wf the struct with all the samples
@return the stddev
*/
double	welford_calc_stddev(t_welford *wf)
{
	double	stddev;

	stddev = sqrt(welford_calc_variance(wf));
	return (stddev);
}
