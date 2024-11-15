/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:57:02 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/14 18:53:16 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int atoi(const char *nptr);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int	ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);
size_t  ft_strlen(const char*s);
size_t  ft_strlcat(char* dest, const char* src, size_t siz);
char    *ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char    *ft_strnstr(const char *big, const char *little,size_t len);
void    *calloc (size_t nmemb, size_t size);

#endif