/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:13:56 by brancari          #+#    #+#             */
/*   Updated: 2026/10/23 16:27:58 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strnlen(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	if (size == 0 || (!dst && size == 0))
		return (ft_strlen(src));
	dstlen = ft_strnlen(dst, size);
	srclen = ft_strlen(src);
	i = 0;
	while (dst[i] && i < size)
		i++;
	if (dst[i] != '\0' && i >= size)
		return (size + ft_strlen(src));
	j = 0;
	while (i < size - 1 && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dstlen + srclen);
}
