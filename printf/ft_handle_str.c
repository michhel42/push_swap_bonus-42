/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:53:34 by vihardy           #+#    #+#             */
/*   Updated: 2025/12/17 15:09:51 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

char	*handle_char(va_list *ap)
{
	char	c;
	char	*str;

	c = (char)va_arg(*ap, int);
	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*handle_str(va_list *ap)
{
	char	*s;
	char	*res;
	int		i;

	i = 0;
	s = va_arg(*ap, char *);
	if (!s)
		return (NULL);
	else
		res = ft_strdup(s);
	if (!res)
		return (NULL);
	return (res);
}

static char	*free_and_null(char *str)
{
	free(str);
	return (ft_strdup("0.0"));
}

char	*handle_float(va_list *ap)
{
	double	nb;
	char	*dec;
	char	*nbr;
	double	deci;

	nb = va_arg(*ap, double);
	if (!nb)
		return (ft_strdup("0.0"));
	deci = (nb - (int)nb) * 100;
	dec = ft_itoa((int)deci);
	if (!dec)
		return (ft_strdup("0.0"));
	nbr = ft_itoa((int)nb);
	if (!nbr)
		return (free_and_null(dec));
	nbr = ft_strjoin(nbr, ".");
	if (!nbr)
		return (free_and_null(dec));
	nbr = ft_strjoin(nbr, dec);
	if (!nbr)
		return (free_and_null(dec));
	free(dec);
	return (nbr);
}
