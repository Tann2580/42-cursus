/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <yanshen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:56:48 by yanshen           #+#    #+#             */
/*   Updated: 2024/11/22 21:31:18 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*newnode;
	void	*content;

	if (!lst || !f)
		return (NULL);
	dest = NULL;
	while (lst)
	{
		content = f(lst->content);
		newnode = ft_lstnew(content);
		if (!newnode)
		{
			del(content);
			ft_lstclear(&dest, del);
			return (NULL);
		}
		ft_lstadd_back(&dest, newnode);
		lst = lst->next;
	}
	return (dest);
}
