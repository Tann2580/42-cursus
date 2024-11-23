/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:08:29 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/22 20:52:21 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intheset(char const c, char const *set)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		j;
	char	*strtrim;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s1);
	start = 0;
	j = 0;
	while (ft_intheset(s1[start], set) && s1[start])
		start++;
	while (end > start && ft_intheset(s1[end - 1], set))
		end--;
	if (start == end)
		return (ft_strdup(""));
	strtrim = malloc(sizeof(char) * (end - start + 1));
	if (!strtrim)
		return (NULL);
	while (start < end)
		strtrim[j++] = s1[start++];
	strtrim[j] = '\0';
	return (strtrim);
}
/*
int	main()
{
	char const *s1 = "1 ";
	char const *set = "";
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
