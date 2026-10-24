/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:46:00 by brancari          #+#    #+#             */
/*   Updated: 2026/10/24 11:25:19 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim(char const *s1, char const *set, char *p)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				i++;
			j++;
		}
		if (set[j] != '\0')
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
//#include <stdio.h>
//int main()
//{
//		char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
//	char *s2 = "Hello \t  Please\n Trim me !";
//	char *ret = ft_strtrim(s1, " \n\t");
//	printf("%s",ret);
//}
