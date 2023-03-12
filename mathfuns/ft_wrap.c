/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:12:54 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/20 14:15:15 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_wrap(int input, int min, int max)
{
	if (input < min)
		return (max - (min - input) % (max - min));
	else
		return (min + (input - min) % (max - min));
}
