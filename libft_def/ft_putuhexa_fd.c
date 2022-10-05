/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhexa_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:22:46 by vicgarci          #+#    #+#             */
/*   Updated: 2022/10/05 19:46:03 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuhexa_fd(unsigned int n, int fd, int mayus)
{
	if (n >= 16)
	{
		ft_putuhexa_fd((n / 16), fd, mayus);
		ft_putuhexa_fd((n % 16), fd, mayus);
	}
	if (n <= 15)
	{
		if (n >= 10)
		{
			if (mayus)
				ft_putchar_fd(n - 10 + 'A', fd);
			else
				ft_putchar_fd(n - 10 + 'a', fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}
