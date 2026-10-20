/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 09:50:54 by brancari          #+#    #+#             */
/*   Updated: 2026/10/17 09:00:37 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	if (little[0] == '\0' || len == 0)
	{
		return ((char *)big);
	}
	i = 0;
	while (big[i])
	{
		j = 0;
		while (little[j] && little[j] == big[j + i])
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)&little[j]);
		}
		i++;
	}
	return (NULL);
}
