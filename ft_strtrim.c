/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <brancari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:01:22 by brancari          #+#    #+#             */
/*   Updated: 2026/10/25 09:22:36 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_copy(int start, int end, char const *s, char *res)
{
	int	i;

	i = 0;
	while (start <= end)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
}

static	char	*check_len_and_malloc(int start, int end)
{
	char	*p;

	if (start > end)
	{
		p = malloc(1);
		if (!p)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	p = malloc (end - start + 2 * (sizeof(char)));
	if (!p)
		return (NULL);
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	if (end > 0)
		end--;
	while (end > start && is_set(s1[end], set))
		end--;
	p = check_len_and_malloc(start, end);
	if (!p)
		return (NULL);
	ft_copy(start, end, s1, p);
	return (p);
}
