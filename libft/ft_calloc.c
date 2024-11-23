/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:30:00 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/22 21:21:08 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dst;

	dst = malloc(size * nmemb);
	if (!dst)
		return (NULL);
	ft_memset(dst, 0, size * nmemb);
	return (dst);
}
