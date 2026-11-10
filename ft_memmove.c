/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <brancari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 10:42:54 by brancari          #+#    #+#             */
/*   Updated: 2026/11/09 18:22:56 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	back_copy(unsigned char *dest, unsigned char *src, size_t n)
{
	while (n > 0)
	{
		n--;
		dest[n] = src[n];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ssrc;
	unsigned char	*dst;

	if (!dest && !src)
		return (NULL);
	dst = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	i = 0;
	if (dst > ssrc)
		back_copy(dst, ssrc, n);
	else
	{
		while (i < n)
		{
			dst[i] = ssrc[i];
			i++;
		}
	}
	return (dest);
}
