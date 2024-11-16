/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:55:03 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/14 14:57:15 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main ()
{
    char str[] = "abcd";
    int c = 'c';
	write (1, ft_strchr(str, c), 1);

	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isdigit('1'));
	printf("%d\n", ft_isalnum('1'));
	printf("%d\n", ft_toupper('a'));
	printf("%d\n", ft_tolower('B'));
	printf("%zu\n", ft_strlen("abcde"));
	printf("%d\n", ft_isprint('c'));
}
