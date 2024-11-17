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
	int	start;
	int	end;
	int	counter;

	start = 0;
	end = ft_strlen(s1);
	counter = 0;
	while (s1[start] && ft_intheset(s1[start++], set))
		counter++;
	while (s1[end] && ft_intheset(s1[end--], set))
		counter++;
	return (ft_strlen(s1) - counter + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		j;
	char	*strtrim;

	if (!set)
		return ((char *)s1);
	strtrim = malloc(sizeof(char const) * (ft_setup(s1, set)));
	if (!strtrim)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	j = 0;
	while (ft_intheset(s1[start], set) && s1[start])
		start++;
	while (ft_intheset(s1[end - 1], set) && end > 0)
		end--;
	while (start < end)
		strtrim[j++] = s1[start++];
	strtrim[j] = '\0';
	return (strtrim);
}
/*
int	main()
{
	char const *s1 = "1 ";
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
