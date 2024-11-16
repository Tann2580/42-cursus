/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:08:29 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/16 19:10:15 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_intheset(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int	ft_setup(char const *s1, char const *set)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s1[i])
	{
		if (ft_intheset(s1[i], set))
			counter++;
		i++;
	}
	return (ft_strlen(s1) - counter + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*strtrim;

	if (!set)
		return ((char *)s1);
	strtrim = malloc(sizeof(char const) * (ft_setup(s1, set)));
	if (!strtrim)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
	{
		while (ft_intheset(s1[i], set) && s1[i])
			i++;
		strtrim[j++] = s1[i++];
	}
	strtrim[j] = '\0';
	return (strtrim);
}
/*
int	main()
{
	char const *s1 = "abc da ,, adsl,,,";
	char const *set = ", ";
	char	*str = ft_strtrim(s1, set);
	
	write(1, str, ft_strlen(str));
}

abc da , aslds
 * abcdaaslds
 * check if char in the set
 * -->yes find the next char check if in the set and if the end
 *  		copy char in the char*temp
 * -->no copy char in the char*temp
 */
