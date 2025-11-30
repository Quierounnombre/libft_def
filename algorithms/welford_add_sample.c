#include "../libft.h"

/*
Add the values of a new sample
@Param wf a welford data struct
@Param sample a double with the value to add
*/
void	welford_add_sample(t_welford *wf, double sample)
{
	double delta_new;
	double delta_old;

	wf->n_samples++;
	delta_new = sample - wf->mean;
	wf->mean += delta_new / wf->n_samples;
	delta_old = sample - wf->mean;
	wf->sqrd_mean = delta_new * delta_old;
}
