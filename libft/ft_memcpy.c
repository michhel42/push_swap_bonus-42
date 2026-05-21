/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:07:09 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/11 11:52:53 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				i;

	s1 = (unsigned char *) dest;
	s2 = (unsigned char *) src;
	i = 0;
	if (!dest && !src)
		return (0);
	while (n > 0)
	{
		s1[i] = s2[i];
		i++;
		n--;
	}
	return (dest);
}
