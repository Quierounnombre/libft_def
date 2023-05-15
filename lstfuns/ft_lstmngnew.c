/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmngnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:01:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/15 18:18:30 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	ft_lstmngnew(t_list *lst, t_lstmng **ext_mng)
{
	t_lstmng	*mng;

	mng = (t_lstmng *)malloc(sizeof(t_lstmng));
	if (mng)
	{
		mng->lst_head = lst;
		mng->size = ft_lstsize(lst);
		mng->tail = ft_lstlast(lst);
		mng->current = lst;
		*ext_mng = mng;
		return (true);
	}
	return (false);
}
