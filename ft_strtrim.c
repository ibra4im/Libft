/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:46:00 by brancari          #+#    #+#             */
/*   Updated: 2026/10/20 09:49:30 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim(char const *s1, char const *set, char *p)
{
	int	i;
	int	j;
	int	index;

	index = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
		{
			p[index] = s1[i];
			index++;
		}
		i++;
	}
	p[index] = '\0';
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;

	if (!s1 || !set)
		return (NULL);
	p = malloc(ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	p = trim(s1, set, p);
	return (p);
}
