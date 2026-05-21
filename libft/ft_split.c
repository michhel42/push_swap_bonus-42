/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:12:28 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/19 15:37:15 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	word;
	int	i;

	count = 0;
	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && word == 0)
		{
			count++;
			word = 1;
		}
		if (s[i] == c)
			word = 0;
		i++;
	}
	return (count);
}

static void	free_all(char **split, int k)
{
	while (k > 0)
	{
		free(split[k - 1]);
		k--;
	}
	free(split);
}

static int	set_word(char **split, int words, const char *s, char c)
{
	int	start;
	int	end;
	int	k;

	start = 0;
	end = 0;
	k = 0;
	while (words > 0)
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] != c && s[end])
			end++;
		split[k] = ft_substr(s, start, end - start);
		if (!split[k])
		{
			free_all(split, k);
			return (0);
		}
		k++;
		words--;
	}
	split[k] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**split;

	if (!s)
		return (0);
	words = count_words(s, c);
	split = (char **) malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (0);
	if (!set_word(split, words, s, c))
		return (0);
	return (split);
}

/*int main(void)
{
	char **tab;
	printf("check 1:%d\n", strcmp(tab[0], "tripouille"));
	printf("taille %d - %d\n",strlen(tab[0]), strlen("tripouille"));
	printf("check 2:%d\n",tab[1] == 0);
	//printf("taille %d - %d\n",strlen(tab[1]), strlen("42"));
	//printf("check 3:%d",tab[2] == NULL);
	tab = ft_split("hello!",' ');
	free_all(tab,1);
	return (0);
}*/
