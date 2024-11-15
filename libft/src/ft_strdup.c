/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:20:30 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/14 18:53:32 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char    *strdup(const char *s)
{
    char  *dst;

    dst = malloc(sizeof(char) * ft_strlen(s) + 1);
    if (!dst)
        return (NULL);
    ft_strcpy(dst, s);
    return (dst);
}