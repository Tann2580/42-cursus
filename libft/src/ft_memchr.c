/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:15:30 by marvin            #+#    #+#             */
/*   Updated: 2024/11/15 21:15:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *memchr(const void *s, int c, size_t n)
{
    const unsigned char *ptr;

    ptr = (const unsigned char *)s;
    while (n--)
    {
        if (*ptr == (unsigned char)c)
            return ((void *)ptr);
        ptr++;
    }
    return (NULL);
}