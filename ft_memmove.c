/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: brancari <brancari@student.1337.ma>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 10:42:54 by brancari          #+#    #+#             */
/*   Updated: 2026/10/22 09:17:57 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_overllap(unsigned char *dest, unsigned char *src, size_t n)
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
		ft_overllap(dst, ssrc, n);
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
