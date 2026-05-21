/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:52:40 by vihardy           #+#    #+#             */
/*   Updated: 2025/11/28 18:27:26 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_putstr(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len != 0)
		write(OUTPUT, s, len);
	return (len);
}

int	count_hex(unsigned long i)
{
	int	count;

	if (i == 0)
		return (1);
	count = 0;
	while (i > 0)
	{
		count++;
		i /= 16;
	}
	return (count);
}

int	find_char(int c, char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	print_space(int i)
{
	int	count;

	count = 0;
	while (i-- > 0)
		count += write(OUTPUT, " ", 1);
	return (count);
}

int	find_precision(const char *str, int *i)
{
	if (str[*i] == '.')
	{
		*i = *i + 1;
		return (ft_basic_atoi(str, i));
	}
	return (-1);
}
