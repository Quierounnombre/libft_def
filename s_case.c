/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:12:44 by vicgarci          #+#    #+#             */
/*   Updated: 2022/10/04 20:35:16 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	s_case(char	*s)
{
	int	len;

	if (s)
	{
		len = ft_strlen(s);
		write(1, s, len);
		return (len);
	}
	write(1, "(null)", 6);
	return (6);
}
