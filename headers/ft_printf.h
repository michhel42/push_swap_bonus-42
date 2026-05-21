/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:25:09 by vihardy           #+#    #+#             */
/*   Updated: 2025/12/17 15:14:57 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# ifndef OUTPUT
#  define OUTPUT 2
# endif

typedef char	*(*t_prt)(va_list *);
typedef struct s_options
{
	char				*type;
	t_prt				prt;
	struct s_options	*next;
}	t_options;

typedef struct s_res
{
	char	*type;
	char	*str;
	char	*flags;
	int		width;
	int		precision;
}	t_res;

/* Function declarations */
t_options	*ft_lstnew(char *opt, t_prt prt);
t_options	*gen_list_options(char *first_opt, ...);
t_options	*print_options(const char *str, int *i, t_options *options);
t_options	*init_options(void);
void		ft_lstadd_back(t_options **lst, t_options *new);
int			ft_lstclear(t_options **lst);
void		free_res(t_res *res);
void		ft_bzero(void *s, size_t n);
char		*ft_itoa(int n);
char		*ft_uitoa(unsigned int nb);
char		*ft_itohex(unsigned long nb, int len, char *hex);
/* Handlers */
char		*handle_char(va_list *ap);
char		*handle_str(va_list *ap);
char		*handle_addr(va_list *ap);
char		*handle_hex(va_list *ap);
char		*handle_upper_hex(va_list *ap);
char		*handle_int(va_list *ap);
char		*handle_unsigned_int(va_list *ap);
char		*handle_float(va_list *ap);

char		*find_flags(const char *str, int *i);
int			find_precision(const char *str, int *i);
int			ft_putstr(char *s);
int			print_space(int i);
int			find_char(int c, char *str);
int			count_hex(unsigned long i);
int			len_with_flags(t_res *res);
int			apply_flags(t_res *res);
int			handle_percent(const char *str, int *i,
				va_list *args, t_options *opts);
int			ft_printf(const char *str, ...);
int			add_sign(t_res *res, char *final_res, int len);
#endif