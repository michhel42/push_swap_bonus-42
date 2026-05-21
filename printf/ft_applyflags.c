/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:56:05 by vihardy           #+#    #+#             */
/*   Updated: 2025/12/10 11:33:32 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

void	fill_with_zero(char *res, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		res[i] = '0';
		i++;
	}
	res[i] = '\0';
}

char	*init_res(int len, char *type, char *flags)
{
	char	*res;

	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (find_char(type[0], "diuxX"))
		fill_with_zero(res, len);
	if (find_char('#', flags) && find_char(type[0], "xX") && len > 1)
		res[1] = type[0];
	return (res);
}

int	add_sign(t_res *res, char *final_res, int len)
{
	int	is_plus;
	int	is_space;

	is_plus = find_char('+', res->flags);
	is_space = find_char(' ', res->flags);
	if (!find_char(res->type[0], "di"))
		return (0);
	if (res->str[0] == '-')
	{
		final_res[0] = '-';
		return (1);
	}
	if (is_plus)
		final_res[0] = '+';
	else if (is_space)
		final_res[0] = ' ';
	if ((is_plus || is_space) && len == 1
		&& res->precision == 0 && res->str[0] == '0')
		return (1);
	return (0);
}

int	print_width(t_res *res, int len, char *final_res)
{
	int	space;
	int	count;

	space = res->width - len;
	count = 0;
	if (!find_char('-', res->flags))
		count += print_space(space);
	if (find_char('c', res->type))
		write(OUTPUT, final_res, 1);
	else
		ft_putstr(final_res);
	if (find_char('-', res->flags))
		count += print_space(space);
	free(final_res);
	free_res(res);
	return (count + len);
}

int	apply_flags(t_res *res)
{
	char	*final_res;
	int		len;
	int		len_res;
	int		i;
	int		j;

	len = len_with_flags(res);
	final_res = init_res(len, res->type, res->flags);
	if (!final_res || (!res->str && find_char('c', res->type)))
	{
		if (final_res)
			free(final_res);
		free_res(res);
		return (-1);
	}
	i = 0;
	j = add_sign(res, final_res, len);
	len_res = ft_strlen(res->str);
	if (find_char('c', res->type))
		final_res[0] = res->str[0];
	while (i < (len - (len_res - j)))
		i++;
	while (i < len)
		final_res[i++] = res->str[j++];
	return (print_width(res, len, final_res));
}
