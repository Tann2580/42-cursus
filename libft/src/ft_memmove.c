/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:24:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/16 02:24:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptrsrc;
	unsigned char		*ptrdest;

	ptrsrc = (const unsigned char *)src;
	ptrdest = (unsigned char *)dest;
	if (ptrsrc == ptrdest)
		return (dest);
	if (ptrdest > ptrsrc)
	{
		ptrdest = n + ptrdest -1;
		ptrsrc = n + ptrsrc -1;
		while (n--)
			*ptrdest-- = *ptrsrc--;
	}
	else
	{
		while (n--)
			*ptrdest++ = *ptrsrc++;
	}
	return (dest);
}
