/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:03:28 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/19 15:02:09 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	j;

	j = 0;
	if (start > (unsigned int) ft_strlen(s))
	{
		sub = (char *) malloc(sizeof(char));
		if (!sub)
			return (0);
		sub[0] = '\0';
		return (sub);
	}
	if (len + start > (unsigned long) ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (s[start] && j < len)
	{
		sub[j] = s[start];
		start++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
