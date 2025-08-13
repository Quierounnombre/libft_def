#include "../libft.h"

/*
Provides a timer, starts when the funtion is called for the first time
@return the timeval difference between the first call, and the current call
*/
struct timeval	ft_timer(void)
{
	static struct timeval	start;
	struct timeval			measured;
	struct timeval			result;

	result.tv_sec = 0;
	result.tv_usec = 0;
	if (start.tv_sec== 0)
		gettimeofday(&start, NULL);
	else
	{
		gettimeofday(&measured, NULL);
		result.tv_sec = measured.tv_sec - start.tv_sec; 
		result.tv_usec = measured.tv_usec - start.tv_usec;
	}
	return (result);
}