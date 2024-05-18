/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:04:55 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/11 11:14:12 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		a;
	size_t				i;

	str = (unsigned char *)s;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == a)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
/*
int main (void)
{
	const char s [] = "adam.chh";
	char c = '.';
	char *ret;

	ret = ft_memchr(s,c,3);
	printf("%s",ret);
	return (0);
}*/
