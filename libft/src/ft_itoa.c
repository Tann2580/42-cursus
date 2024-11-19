/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:20:23 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/18 14:02:02 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nb_int(int n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		counter++;
		n = -n;
	}
	if (n == 0)
		counter = 1;
	while (n > 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		sign;

	sign = 0;
	len = nb_int(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		sign = 1;
	}
	str[len] = '\0';
	while (len > sign)
	{
		str[len - sign] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}
/*
int	main()
{
	int	ac = -123;
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
