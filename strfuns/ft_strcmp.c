/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:01:27 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/15 19:07:53 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Compara dos strings, retorna un boleano con verdadero o falso
@param s1 primer string a comparar
@param s2 segundo string a comparar
@return devuelve true si ambos son identicos en contenido y tamaño, en caso
contrario devuelve false
*/
t_bool	ft_strcmp(char const *s1, char const *s2)
{
	while (s1 && s2)
	{
		if (*s1 != *s2)
			return (false);
		s1++;
		s2++;
	}
	if (s1 || s2)
		return (false);
	return (true);
}
