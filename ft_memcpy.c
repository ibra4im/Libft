/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:26:24 by brancari          #+#    #+#             */
/*   Updated: 2026/10/21 08:32:51 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptrtodst;
	unsigned char	*ptrtosrc;

	ptrtodst = (unsigned char *)dest;
	ptrtosrc = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		ptrtodst[i] = ptrtosrc[i];
		i++;
	}
	return (dest);
}

int	main(void)
{
	int	dest;
	int	src = 1337;

	ft_memcpy(&dest, &src, 4);
	printf("%d", dest);
}
