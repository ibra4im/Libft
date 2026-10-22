/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:13:56 by brancari          #+#    #+#             */
/*   Updated: 2026/10/22 11:39:49 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		lenofsrc;
	size_t	i;
	int		j;
	int		lenofdst;

	lenofsrc = 0;
	lenofdst = 0;
	i = 0;
	j = 0;
	while (src[lenofsrc] != '\0')
	{
		lenofsrc++;
	}
	while (dst[j])
	{
		j++;
	}
	lenofdst = j;
	while (i < size -1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	return (lenofdst + lenofsrc);
}
#include <stdio.h>
int main()
{
	char *src = "the cake is a lie !\0I'm hidden lol\r\n";
	char dest[100]  = "there os no stars in the sky";
	ft_strlcat(dest,src,100);
	printf("%s",dest);
}
