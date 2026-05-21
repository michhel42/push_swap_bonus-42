/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:19:58 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/11 13:19:45 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	s = src;
	d = dest;
	i = 0;
	if (d > s)
	{
		while (++i <= n)
			d[n - i] = s[n - i];
	}
	else
	{
		while (n-- > 0)
		{
			*(d++) = *(s++);
		}
	}
	return (dest);
}
