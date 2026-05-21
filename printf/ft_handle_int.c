/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:55:03 by vihardy           #+#    #+#             */
/*   Updated: 2025/12/20 14:25:19 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*handle_addr(va_list *ap)
{
	unsigned long	addr;
	char			*hex;
	char			*res;
	int				len;

	addr = (unsigned long)va_arg(*ap, void *);
	if (!addr)
		return (ft_strdup("(nil)"));
	hex = "0123456789abcdef";
	len = count_hex(addr) + 2;
	res = ft_itohex(addr, len, hex);
	if (!res)
		return (NULL);
	res[1] = 'x';
	return (res);
}

char	*handle_hex(va_list *ap)
{
	unsigned int	nb;
	char			*hex;
	char			*res;
	int				len;

	nb = va_arg(*ap, unsigned int);
	hex = "0123456789abcdef";
	len = count_hex(nb);
	res = ft_itohex(nb, len, hex);
	if (!res)
		return (NULL);
	return (res);
}

char	*handle_upper_hex(va_list *ap)
{
	unsigned int	nb;
	char			*hex;
	char			*res;
	int				len;

	nb = va_arg(*ap, unsigned int);
	hex = "0123456789ABCDEF";
	len = count_hex(nb);
	res = ft_itohex(nb, len, hex);
	if (!res)
		return (NULL);
	return (res);
}

char	*handle_int(va_list *ap)
{
	char	*res;

	res = ft_itoa(va_arg(*ap, int));
	if (!res)
		return (NULL);
	return (res);
}

char	*handle_unsigned_int(va_list *ap)
{
	char	*res;

	res = ft_uitoa(va_arg(*ap, unsigned int));
	if (!res)
		return (NULL);
	return (res);
}
