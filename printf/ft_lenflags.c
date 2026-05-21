/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:57:16 by vihardy           #+#    #+#             */
/*   Updated: 2025/12/17 15:13:46 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	flag_hexa(char *str, char *type, char *flags)
{
	int	is_flag;
	int	len;
	int	is_type;

	is_flag = find_char('#', flags);
	is_type = (find_char('x', type) || find_char('X', type));
	len = ft_strlen(str);
	if (is_flag && is_type && !(len == 1 && str[0] == '0'))
		return (2);
	return (0);
}

int	gestion_str(t_res *res, int len)
{
	if (!res->str)
	{
		res->str = ft_strdup("(null)");
		if (res->precision == -1 || res->precision >= 6)
			len = 6;
		else if (res->precision < 6)
			len = 0;
	}
	else if (res->precision <= len && res->precision >= 0)
		len = res->precision;
	return (len);
}

int	check_sign(t_res *res)
{
	int	flag_sign;
	int	flag_space;
	int	sign;

	flag_sign = find_char('+', res->flags);
	flag_space = find_char(' ', res->flags);
	sign = res->str[0] == '-';
	return (flag_sign || flag_space || sign);
}

int	precision_len(t_res *res, int len)
{
	int	sign;
	int	is_num;
	int	flag_sign;
	int	flag_space;
	int	op;

	flag_sign = find_char('+', res->flags);
	flag_space = find_char(' ', res->flags);
	op = res->str[0] == '-';
	sign = op || flag_space || op;
	is_num = find_char(res->type[0], "diuxX");
	sign = check_sign(res);
	if (len == 1 && res->precision == 0 && res->str[0] == '0' && is_num)
		len = 0 + sign;
	else if (res->precision > len - sign)
		len = res->precision + sign;
	else if ((flag_space || flag_sign) && !op && is_num)
		len += 1;
	return (len);
}

int	len_with_flags(t_res *res)
{
	int	len;

	len = ft_strlen(res->str);
	if (find_char('s', res->type))
		return (gestion_str(res, len));
	if (find_char('c', res->type))
		len = 1;
	else
		len = precision_len(res, len);
	len += flag_hexa(res->str, res->type, res->flags);
	if (len < res->width && find_char('0', res->flags)
		&& !find_char('-', res->flags) && res->precision == -1
		&& !find_char('c', res->type))
		len = res->width;
	return (len);
}
