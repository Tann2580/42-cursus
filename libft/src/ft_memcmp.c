/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:16:29 by marvin            #+#    #+#             */
/*   Updated: 2024/11/16 03:16:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *ptrs1;
    const unsigned char *ptrs2;

    ptrs1 = (const unsigned char)s1;
    ptrs2 = (const unsigned char *)s2;
    while (n--)
    {{
        if (*ptrs1 != *ptrs2)
            return (*ptrs1 - *ptrs2);
        ptrs1++;
        ptrs2++;
    }
    return (*ptrs1 -*ptrs2);
}