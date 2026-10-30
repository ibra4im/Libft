/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <brancari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:10:59 by brancari          #+#    #+#             */
/*   Updated: 2026/10/28 08:44:23 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*fill(long n, int sign, int len, char *res)
{
	if (sign == -1)
	{
		res[0] = '-';
	}
	res[len] = '\0';
	len--;
	while (n > 0)
	{
		res[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		sign;
	int		len;
	long	i;

	i = n;
	len = 0;
	sign = 1;
	if (n == 0)
		return (ft_strdup("0"));
	if (i < 0)
	{
		sign = -1;
		i *= -1;
		len = 1;
	}
	len = len + get_len(i);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res = fill(i, sign, len, res);
	return (res);
}
