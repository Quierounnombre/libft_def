/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:14:54 by vicgarci          #+#    #+#             */
/*   Updated: 2022/10/05 14:42:10 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	potenciarecursiva(int numero, int potencia)
{
	if (potencia <= 0)
	{
		return (1);
	}
	else
	{
		return (numero * potenciarecursiva(numero, potencia - 1));
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int		resultado;
	int		i;
	int		j;
	int		n;
	int		m;

	i = -1;
	j = -1;
	m = ft_strlen(base);
	n = ft_strlen(str);
	resultado = 0;
	while (i++ < n)
	{
		while (j++ < (m - 1))
		{
			if (str[i] == base[j])
			{
				resultado += (j * potenciarecursiva(m, (n - i)));
				j = m;
			}
		}
		j = 0;
	}
	resultado = resultado / m;
	return (resultado);
}
