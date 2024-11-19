/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:23:35 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/16 18:08:09 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}
/*
int	main()
{
	char	*dest;
	char	*s1 = "";
	char	*s2 = "";

	dest = ft_strjoin(s1, s2);
	write(1, dest, ft_strlen(dest));
}

create the array with space of ft_strlen(s1)+ft_strlen(s2) + 1 
 * copy all the byte till the end of s1
 * while (s1)
 * dest[i] = s1[i]
 * i++
 * dest i = 0
 * return dest
 * get to the end of dest 
 * len = ft_strlen(dest)
 * i = 0
 * dest[len + i] = s2[i];
 * dest[len + i] = \0*/
