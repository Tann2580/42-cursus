/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:46:46 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/22 20:22:16 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c <= 13 && c >= 9) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	nbsign_n;

	i = 0;
	nb = 0;
	nbsign_n = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			nbsign_n = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nbsign_n * nb);
}
/*
int	main()
{
	char s[] = "+548";
	printf("%d\n", ft_atoi(s));
}
*/
