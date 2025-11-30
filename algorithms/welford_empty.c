#include "../libft.h"

/*
Sets the welford struct to 0
@param wf the welfor struct to set to 0
*/
void	welford_empty(t_welford *wf)
{
	wf->n_samples = 0;
	wf->mean = 0.0;
	wf->sqrd_mean = 0.0;
}
