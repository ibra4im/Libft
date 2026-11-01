/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <brancari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 09:58:40 by brancari          #+#    #+#             */
/*   Updated: 2026/11/01 17:30:44 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char const s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	count_word(char const *str, char charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_charset(charset, str[i]))
			i++;
		if (str[i] && !is_charset(charset, str[i]))
		{
			count++;
			while (str[i] && !is_charset(charset, str[i]))
				i++;
		}
	}
	return (count);
}

static char	*malloc_string(char const *str, char charset)
{
	int		i;
	char	*word;
	int		len;

	i = 0;
	len = 0;
	while (str[len] && !is_charset(charset, str[len]))
	{
		len++;
	}
	word = malloc((len * sizeof(char)) + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**free_all(char **p, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(p[i]);
		i++;
	}
	free (p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		j;

	if (!s)
		return (NULL);
	arr = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s && is_charset(c, *s))
			s++;
		if (*s)
		{
			arr[j] = malloc_string(s, c);
			if (!arr[j])
				return (free_all(arr, j));
			j++;
			while (*s && !is_charset(c, *s))
				s++;
		}
	}
	arr[j] = NULL;
	return (arr);
}
