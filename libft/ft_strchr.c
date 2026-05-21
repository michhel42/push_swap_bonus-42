/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:22:39 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/11 15:12:11 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*ch;
	char	t;
	int		i;

	i = 0;
	ch = (char *) s;
	t = (char) c;
	while (ch[i])
	{
		if (ch[i] == t)
			return (&ch[i]);
		i++;
	}
	if (ch[i] == t)
		return (&ch[i]);
	return (0);
}
