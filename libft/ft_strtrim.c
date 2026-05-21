/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:34:36 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/19 15:04:46 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_set(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && is_set((char *) set, s1[i]))
		i++;
	while (--j >= 0 && is_set((char *) set, s1[j]))
		;
	if (j < i)
	{
		str = malloc(1);
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	str = ft_substr(s1, i, j - i + 1);
	return (str);
}

/*#include <string.h>

int main(void)
{
	char *s1 = "Hello \t  Please\n Trim me !";
 	char *s2 = "Hello \t  Please\n Trim me !";
 	char *ret = ft_strtrim(" . abcd . ", " ");
	printf("'%s'", ret); 
 	if (!strcmp(ret, s2))
 		exit(1);
 	exit(0);

	return (0);
}*/
