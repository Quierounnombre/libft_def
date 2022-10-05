/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:47:37 by vicgarci          #+#    #+#             */
/*   Updated: 2022/09/19 16:57:24 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int				i;
	const t_list	*temp;

	i = 0;
	temp = (const t_list *) lst;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
