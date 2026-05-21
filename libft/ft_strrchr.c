/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:27:29 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/11 13:07:35 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ch;
	int		i;
	int		j;

	c = c % 256;
	i = 0;
	j = -1;
	ch = (char *) s;
	while (ch[i])
	{
		if (ch[i] == c)
			j = i;
		i++;
	}
	if (ch[i] == c)
		j = i;
	if (j == -1)
		return (0);
	return (&ch[j]);
}
