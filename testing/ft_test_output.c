/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:16:31 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/10 17:27:49 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//Imprime con un salto de linea la cadena en función del resultado
void	ft_test_output(t_bool result, char *s)
{
	if (result)
		ft_printf("\033[32m%s", s);
	else
		ft_printf("\33[31m%s", s);
	ft_printf("\033[39m\n");
}
