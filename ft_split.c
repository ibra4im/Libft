/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 09:58:40 by brancari          #+#    #+#             */
/*   Updated: 2026/10/20 10:53:36 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i - 1] != c && s[i] == c))
		{
			words++;
		}
		i++;
	}
	return (words);
}

static char	*fill(char const *s, char c, char **p)
{
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**p;
	int		words;

	i = 0;
	words = count_words(s, c);
	p = malloc((char **) words + 1);
	if (!p)
		return (NULL);
}
