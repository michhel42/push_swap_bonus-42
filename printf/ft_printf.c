/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:22:11 by vihardy           #+#    #+#             */
/*   Updated: 2025/12/28 16:27:54 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

char	*find_flags(const char *str, int *i)
{
	char	*flags;
	char	*res;
	int		j;

	flags = "-+0 #";
	res = malloc(6);
	if (!res)
		return (NULL);
	ft_bzero(res, 6);
	*i = *i + 1;
	j = 0;
	while (str[*i] && find_char((int)str[*i], flags))
	{
		if (!find_char((int)str[*i], res))
			res[j++] = str[*i];
		(*i)++;
		if (j >= 5)
			break ;
	}
	res[j] = '\0';
	return (res);
}

void	free_res(t_res *res)
{
	free(res->flags);
	free(res->str);
	free(res);
}

int	verif_opt(const char *str, t_res *res, t_options *opt)
{
	free(res->flags);
	free(res);
	if (!*str || !opt)
		return (-1);
	if (!opt->prt && opt->type && !find_char('%', opt->type))
		return (write(OUTPUT, "%", 1) + write(OUTPUT, opt->type, 1));
	return (write(OUTPUT, "%", 1));
}

int	handle_percent(const char *str, int *i, va_list *args, t_options *opts)
{
	t_options	*opt;
	t_res		*res;

	res = malloc(sizeof(t_res));
	if (!res)
		return (-1);
	res->flags = find_flags(str, i);
	if (!res->flags)
	{
		free(res);
		return (-1);
	}
	res->width = ft_basic_atoi(str, i);
	res->precision = find_precision(str, i);
	opt = print_options(str, i, opts);
	if (!opt || !opt->prt)
		return (verif_opt(str, res, opt));
	res->str = opt->prt(args);
	res->type = opt->type;
	if (opt->prt)
		return (apply_flags(res));
	free_res(res);
	return (write(OUTPUT, "%", 1));
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_options	*opts;
	int			i;
	int			count;

	i = 0;
	count = 0;
	opts = init_options();
	if (!opts || !str)
		return (ft_lstclear(&opts));
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			count += handle_percent(str, &i, &args, opts);
		else
		{
			write(OUTPUT, &str[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	ft_lstclear(&opts);
	return (count);
}

/*
int main(void)
{
	ft_printf("%o test");
	return (0);
}*/