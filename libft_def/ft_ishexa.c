/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:03:25 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/24 15:49:11 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_ishexa(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))
		return (true);
	return (false);
}
