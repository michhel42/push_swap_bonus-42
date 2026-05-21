/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:22:39 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/11 14:26:31 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ch;
	unsigned char	t;
	size_t			i;

	i = 0;
	ch = (unsigned char *) s;
	t = (unsigned char) c;
	while (i < n)
	{
		if (ch[i] == t)
			return (&ch[i]);
		i++;
	}
	return (0);
}
