/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 08:42:29 by brancari          #+#    #+#             */
/*   Updated: 2026/10/22 16:49:18 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*helper_join(char const *s1, char const *s2, char *join)
{
	int	i;
	int	j;
	int	s1len;
	int	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	while (i < s1len)
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2len)
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		totallen;
	char	*join;

	totallen = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(totallen + 1 * (sizeof(char)));
	if (!join)
		return (NULL);
	join = helper_join(s1, s2, join);
	return (join);
}
