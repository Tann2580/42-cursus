/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:20:23 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/22 20:22:32 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_int(int n)
{
	int			counter;
	long long	nbr;

	nbr = n;
	counter = 0;
	if (n < 0)
	{
		counter++;
		nbr = -nbr;
	}
	if (nbr == 0)
		counter = 1;
	while (nbr > 0)
	{
		nbr /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	int			sign;
	long long	nbr;

	nbr = n;
	sign = 0;
	len = nb_int(nbr);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
		sign = 1;
	}
	str[len] = '\0';
	while (len > sign)
	{
		str[len - 1] = (nbr % 10) + 48;
		nbr = nbr / 10;
		len--;
	}
	return (str);
}
/*
int	main()
{
	int	ac = 9;
	printf("%s\n", ft_itoa(ac));
}
number of character
 * if sign 
 * create the space with malloc 
 * put the number in each place 
 *-123546789
 n = 0 len = 1
 n = -0 len = 1
 n = -2 len = 2 str[len] = \0
 n = 123 len = 3 str[len] = \0 str[2] = 3 str[1] = 2 str[0] = 1
 */
