/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:13:52 by vicgarci          #+#    #+#             */
/*   Updated: 2022/09/19 19:57:30 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "string.h"
# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"
# include "stdarg.h"
# include "limits.h"
# include "stdint.h"
# include "signal.h"
# include "fcntl.h"
# include "math.h"
# include <sys/time.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef enum KXA_BFAL
{
	Bug = 0
}	t_KXA_BFAL;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

typedef struct s_lstmng
{
	struct s_list	*lst_head;
	struct s_list	*tail;
	struct s_list	*current;
	int				size;
}			t_lstmng;

typedef enum e_bool
{
	false = 0,
	true = 1
}			t_bool;

typedef struct s_vector3D
{
	float	x;
	float	y;
	float	z;
}			t_vector3D;

typedef struct s_vector2D
{
	float	x;
	float	y;
}			t_vector2D;

/*
Welford algorithm for calculating a running mean
*/

/*
Holy bible 
https://www.embeddedrelated.com/showarticle/785.php
*/

typedef struct s_welford
{
	int		n_samples;
	double	mean;
	double	sqrd_mean;
}			t_welford;

/*-----LstFuns-----*/

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstclean(t_list **lst);
t_list		*ft_lstnnode(t_list *lst, size_t n);
t_bool		ft_lstmngnew(t_list *lst, t_lstmng **ext_mng);

/*-----IsControl-----*/

t_bool		ft_isalpha(int c);
t_bool		ft_isdigit(int c);
t_bool		ft_isalnum(int c);
t_bool		ft_isascii(int c);
t_bool		ft_isprint(int c);
t_bool		ft_isspace(int c);
t_bool		ft_ishexa(int c);
t_bool		ft_ismayus(char c);

/*-----StrFuns-----*/

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strchr(const char *src, unsigned int c);
char		*ft_strrchr(const char *src, unsigned int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_atoi(const char *str);
int			ft_atoi_base(char *str, char *base);
char		*ft_itoa(int c);
char		*ft_itoa_base(long long c, char *base);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_bool		ft_strcmp(char const *s1, char const *s2);

/*-----MemsFuns-----*/

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		**ft_2dcalloc(size_t size, size_t datatype, size_t len);
t_bool		ft_store_file(int fd, char **target);

/*-----PutFuns-----*/

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr_base(long int nbr, char *base);
void		ft_putunbr_fd(unsigned int n, int fd);
void		ft_putuhexa_fd(unsigned int n, int fd, int mayus);

/*-----GNL-----*/

char		*ft_get_next_line(int fd);
char		*read_main(char *buffer, int fd);
char		*cut_line(char	*buffer);
char		*take_rest(char *buffer);

/*-----MathFuns-----*/

int			ft_wrap(int input, int min, int max);
t_vector3D	load_vector3d(int i, int j, int k);
int			ft_calc_percent(int total, int part);

/*-----TESTING-----*/

void		ft_test_output(t_bool result, char *s);

/*-----PRINTF-----*/

int			ft_printf(char const *s, ...);
int			cases(const char *s, va_list largv);
int			c_case(char c);
int			di_case(int c);
int			p_case(unsigned long long s);
int			s_case(char	*s);
int			xmin_case(unsigned int hexa);
int			xmax_case(unsigned int hexa);
int			u_case(int c);

/*-----TIMER-----*/

struct timeval	ft_timer(t_bool reset);

/*-----ALGORITHMS-----*/

double		welford_calc_stddev(t_welford *wf);
double		welford_calc_variance(t_welford *wf);
void		welford_add_sample(t_welford *wf, double sample);
void		welford_empty(t_welford *wf);

#endif
