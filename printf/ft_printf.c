/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:19:15 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/24 00:00:31 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *, ...)


int	ifint
int	ifchar

/*printf 
 * first argument -> format specifier 
 *the pointer to the rest of the arguments is set pointing to after that argument by advancing it sizeof(char*)bytes
 Depending on the contents of the format specifier. the offset of the pointer is advanced.
 	eg:"%c" advances the argument pointer one byte telling the fonction that it should interpret what it points to as a character. "%d"would advance it sizeof(int)bytes and then interpret the valuses as an integer

So the format specifier is used to determie the way the value that the pointer is pointing to, should be interpreted and then passed to a low level IO routine. It is also the biggeset drawback with printf since if you do not match number of format specifiers with actual number of arguments you may cause a stack overflow or worse.

/*OUTPUT
The fonction printf() write output to stdout --> 1
*/

/* FORMAT STRING--> CHARACTER STRING (>=0)
if format string (start with % then )
	get >=0 arguments and convert
if not strncpy

*/