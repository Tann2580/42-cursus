/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:46:46 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/14 18:16:02 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isspace (char c)
{
    if ((c <= 13 && c >= 9) || c == 32)
        return (1);
    return (0);
}

int atoi(const char *nptr)
{
    int i;
    int nb;
    int nbsign_n;

    i = 0;
    nb = 0;
    nbsign_n = 0;
    while (ft_isspace(nptr[i]))
        i++;
    while (nptr[i] == '-' || nptr[i] == '+')
    {
           if (nptr[i] == '-')
            nbsign_n++;
        i++;
    }
    while (ft_isdigit(nptr[i]))
    {
        nb = nb * 10 + nptr[i] - '0';
        i++;
    }
    if (nbsign_n % 2 == 0)
		nbsign_n = 1;
	else
		nbsign_n = -1;
	return (nbsign_n * nb);
}