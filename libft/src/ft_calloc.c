/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:30:00 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/14 18:48:49 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *calloc (size_t nmemb, size_t size)
{
    char    *dst;

    if (nmemb == 0 || size == 0)
        return (NULL);
    dst = malloc(size * nmemb);
    if (!dst)
        return (NULL);
    memset(dst, 0, size * nmemb);
    return dst;
}