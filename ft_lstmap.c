/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <brancari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 13:43:29 by brancari          #+#    #+#             */
/*   Updated: 2026/11/01 18:17:48 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*res;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		newnode = ft_lstnew(content);
		if (!newnode)
		{
			del(content);
			ft_lstdelone(res, del);
		}
		ft_lstadd_back(&res, newnode);
		lst = lst->next;
	}
	return (res);
}
