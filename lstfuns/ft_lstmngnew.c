/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmngnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:01:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/04 15:07:12 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	ft_lstmngnew(t_list *lst)
{
	t_lstmng	*mng;

	mng = (t_lstmng *)malloc(sizeof(t_lstmng));
	if (mng)
	{
		mng->lst_head = lst;
		mng->size = ft_lstsize(lst);
		mng->tail = ft_lstlast(lst);
		return (true);
	}
	return (false);
}
