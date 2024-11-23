/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:37:53 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/22 20:37:53 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static char	*ft_word(char const *s, int i, int j)
{
	char	*word;
	int		k;

	k = 0;
	if (i - j > 0)
	{
		word = malloc(sizeof(char) * (i - j + 1));
		if (!word)
			return (NULL);
		while (j < i)
			word[k++] = s[j++];
		word[k] = '\0';
	}
	else
		return (NULL);
	return (word);
}

static void	*ft_free(char **str, int index)
{
	while (--index >= 0)
		free(str[index]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		index;
	int		i;
	int		j;

	i = 0;
	split = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!split)
		return (NULL);
	index = 0;
	while (index < ft_count(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		split[index] = ft_word(s, i, j);
		if (!split[index])
			return (ft_free(split, index));
		index++;
	}
	split[index] = NULL;
	return (split);
}
/*
int	main()
{
	char	*s = ",,,abc,,ddf,,a,,,,af,,";
	char	c = ',';
	char	**split;
	int	i;
	
	i = 0;
	split = ft_split(s, c);
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	return (0);
}
,,,abc,,df,a,,ads,,,
 * count nb words
 * 	if == c i++;
 * 	if !=c i++;
 * 	at the end of the word counter++
 *
 * create nb cases for split
 * create nb chars for each case
 *
 * fill up the cases
 * find the first non c
 */
