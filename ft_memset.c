/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brancari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 09:33:53 by brancari          #+#    #+#             */
/*   Updated: 2026/10/14 09:33:54 by brancari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char * str;
    size_t i;

    str = (unsigned char *)s;
    i = 0;
    while (n >= i)
    {
        str[i] = (unsigned char )c;
        i++;
    }
    return (s);
}


#include <stdio.h>
int main()
{
    int    x = 0;
    void    *holder = &x;
    ft_memset(holder, 0x39, 1);
    ft_memset(holder+1, 0x05, 1);
    ft_memset(holder+2, 0, 1);
    printf("%d\n", x);
}