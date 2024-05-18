/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:00:14 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/11 10:38:24 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s11;
	const unsigned char	*s22;

	i = 0;
	if (n == 0)
		return (0);
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while ((s11[i] == s22[i]) && i < n - 1)
		i++;
	return (s11[i] - s22[i]);
}
/*
int main ()
{
	char s1 [] = "adam";
	char s2 [] = "adamb";
	int n = ft_memcmp(s1,s2,5);
	printf("%d",n);
	return (0);
}*/
