#include "../libft.h"

#define TO_PORCENTAJE 100 

/*
Convert the proportion, into a porcentage
@param Total the total
@param Part the part
@return a int from 0 to 100 (could be more in the case of a bigger part that the total...)
*/
int		ft_calc_percent(int	total, int part)
{
	double	ret;
	
	ret = part / total;
	ret *= TO_PORCENTAJE;
	return (ret);
}