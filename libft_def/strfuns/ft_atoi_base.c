/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:14:54 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/16 16:57:52 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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

static int	mod_strlen(char *str, char *base, int base_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (j != base_size)
		{
			if (base[j] == str[i])
				break ;
			j++;
		}
		if (base_size == j)
			return (i);
		j = 0;
		i++;
	}
	return (i);
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
	n = mod_strlen(str, base, m);
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
