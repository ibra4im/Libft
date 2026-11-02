/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <brancari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:26:24 by brancari          #+#    #+#             */
/*   Updated: 2026/11/01 20:30:01 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptrtodst;
	unsigned char	*ptrtosrc;

	ptrtodst = (unsigned char *)dest;
	ptrtosrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptrtodst[i] = ptrtosrc[i];
		i++;
	}
	return (dest);
}
