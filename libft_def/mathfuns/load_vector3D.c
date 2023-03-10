/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_vector3D.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:45:29 by vicgarci          #+#    #+#             */
/*   Updated: 2023/02/14 16:05:28 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_vector3D	load_vector3d(int i, int j, int k)
{
	t_vector3D	v;

	v.x = (float)i;
	v.y = (float)j;
	v.z = (float)k;
	return (v);
}
