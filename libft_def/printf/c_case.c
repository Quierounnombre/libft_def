/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:12:20 by vicgarci          #+#    #+#             */
/*   Updated: 2022/10/04 19:55:39 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	c_case(char c)
{
	char	*s;

	s = ft_calloc(1, sizeof(char));
	*s = c;
	write(1, s, 1);
	free(s);
	return (1);
}
