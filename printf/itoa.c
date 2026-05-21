/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-13 10:45:57 by vihardy           #+#    #+#             */
/*   Updated: 2026-02-13 10:45:57 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	init_itoa(int n, unsigned int *nb, int *is_neg)
{
	size_t			len;
	unsigned int	temp;

	*is_neg = (n < 0);
	len = 0;
	if (*is_neg)
	{
		*nb = (unsigned int)(-(long)n);
		len++;
	}
	else
		*nb = n;
	temp = *nb;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	if (n == 0)
		return (1);
	return (len);
}

static size_t	init_uitoa(unsigned int nb)
{
	size_t			len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	nb;
	size_t			len;
	int				is_negative;

	len = init_itoa(n, &nb, &is_negative);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[--len] = (char)((nb % 10) + '0');
		nb /= 10;
	}
	if (is_negative)
		res[0] = '-';
	return (res);
}

char	*ft_uitoa(unsigned int nb)
{
	char		*res;
	size_t		len;

	len = init_uitoa(nb);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[--len] = (char)((nb % 10) + '0');
		nb /= 10;
	}
	return (res);
}

char	*ft_itohex(unsigned long nb, int len, char *hex)
{
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = hex[nb % 16];
		nb /= 16;
		len--;
	}
	return (res);
}
