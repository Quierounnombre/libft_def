/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:17:46 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/22 13:20:58 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclean(t_list **lst)
{
	t_list	*first;
	t_list	*next;

	if (*lst)
	{
		first = *lst;
		while (first->next)
		{
			next = first->next;
			free(first);
			first = next;
		}
		free(first);
	}
}
