/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 08:54:28 by brancari          #+#    #+#             */
/*   Updated: 2026/10/14 08:54:29 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        i++;
    }
    return (i);
}

#include <stdio.h>
int main()
{
    printf("%ld",ft_strlen("hello"));
}