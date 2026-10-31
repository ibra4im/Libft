/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <brancari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 10:03:47 by brancari          #+#    #+#             */
/*   Updated: 2026/10/31 10:58:32 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		node = *lst;
		next = node->next;
		del(node->content);
		free(node);
		*lst = next;
	}
	*lst = NULL;
}
