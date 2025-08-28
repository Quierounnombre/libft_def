#include "../libft.h"

/*
Provides a timer, starts when the funtion is called for the first time
@param reset if reset is true restart the clock
@return the timeval difference between the first call, and the current call
*/
struct timeval	ft_timer(t_bool reset)
{
	static struct timeval	start;
	struct timeval			measured;
	struct timeval			result;

	result.tv_sec = 0;
	result.tv_usec = 0;
	if (start.tv_sec== 0 || reset)
		gettimeofday(&start, NULL);
	else
	{
		gettimeofday(&measured, NULL);
		result.tv_sec = measured.tv_sec - start.tv_sec; 
		result.tv_usec = measured.tv_usec - start.tv_usec;
	}
	return (result);
}