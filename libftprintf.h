/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:05:41 by marvin            #+#    #+#             */
/*   Updated: 2022/10/05 00:05:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft_def/libft.h"

int		ft_printf(char const *s, ...);
int		cases(const char *s, va_list largv);

/*---Cases---*/
int		c_case(char c);
int		di_case(int c);
int		p_case(unsigned long long s);
int		s_case(char	*s);
int		xmin_case(unsigned int hexa);
int		xmax_case(unsigned int hexa);
int		u_case(int c);

#endif
