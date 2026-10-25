/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <brancari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:33:27 by brancari          #+#    #+#             */
/*   Updated: 2026/10/22 11:24:40 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		sizeofsrc;

	i = 0;
	sizeofsrc = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[sizeofsrc] != '\0')
	{
		sizeofsrc++;
	}
	while (i < size -1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (sizeofsrc);
}
