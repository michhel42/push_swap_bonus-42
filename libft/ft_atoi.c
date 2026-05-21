/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:34:57 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/12 15:56:44 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_atoi(const char *s)
{
	long int	i;
	int			neg;

	i = 0;
	neg = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
		if (*(s++) == '-')
			neg = -1;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		i *= 10;
		i += (*s % 48);
		if (neg == -1 && i > 2147483648)
			return (0);
		else if (neg == 1 && i > 2147483647)
			return (0);
		s++;
	}
	return ((int) neg * i);
}

int	ft_basic_atoi(const char *nptr, int *i)
{
	int		total;

	total = 0;
	while (nptr[*i] != '\0' && nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		total = (total * 10) + (nptr[*i] - '0');
		*i = *i + 1;
	}
	return (total);
}
