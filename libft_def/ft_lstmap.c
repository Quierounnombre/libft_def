/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:47:34 by marvin            #+#    #+#             */
/*   Updated: 2022/09/20 19:47:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*firstpoint;
	t_list	*lst2;

	if (!lst || !f || !del)
		return (NULL);
	lst2 = ft_lstnew(f(lst->content));
	if (lst2)
	{
		firstpoint = lst2;
		lst = lst->next;
		while (lst)
		{
			lst2->next = ft_lstnew(f(lst->content));
			if (!(lst2->next))
			{
				ft_lstclear(&firstpoint, del);
				return (NULL);
			}
			lst = lst->next;
			lst2 = lst2->next;
		}
		lst2->next = NULL;
		return (firstpoint);
	}
	return (NULL);
}
