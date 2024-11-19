/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:42:37 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/19 13:47:06 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				j;
	unsigned char	cc;	

	cc = (unsigned char)c;
	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == cc)
			j = i;
		i++;
	}
	if (cc == '\0')
		return ((char *)&s[i]);
	if (j == -1)
		return (NULL);
	return ((char *)&s[j]);
}
