/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:57:20 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/16 13:44:43 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t siz)
{
	size_t	init_len_dest;
	size_t	len_src;
	size_t	j;

	j = 0;
	len_src = ft_strlen(src);
	init_len_dest = ft_strlen(dest);
	if (siz <= init_len_dest)
		return (len_src + siz);
	while (src[j] && init_len_dest + j < siz - 1)
	{
		dest[init_len_dest + j] = src[j];
		j++;
	}
	dest[init_len_dest + j] = '\0';
	return (init_len_dest + len_src);
}
