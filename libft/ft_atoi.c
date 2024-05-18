/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:54:32 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/20 19:27:03 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	ft_check(const char *s, int n, int f, int k1)
{
	int	k;

	if (!s)
		return (0);
	while (*s >= 48 && *s <= 57 && *s != '\0')
		s++;
	if (*s != '\0')
		return (n);
	k = ft_strlen(s);
	if (k - k1 == 20 && s[k - 1] == '7')
		return (-1);
	if (k - k1 >= 19)
	{
		if (f == -1)
			return (0);
		else
			return (-1);
	}
	else
		return (n);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	f;
	int	k;

	i = 0;
	n = 0;
	f = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			f = f * -1;
		i++;
	}
	k = i;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (((char *)nptr)[i++] - 48);
	}
	n = ft_check(nptr, n, f, k);
	return (n * f);
}
/*
int main (void)
{
//	const char s[] = "9223372036854775808";
	const char s[] = "-123THERE IS A NYANCAT UNDER YOUR BED";
	int n = ft_atoi(s);
	printf("My aoti =%d\n", n);
	printf("real atoi =%d", atoi(s));
	return (0);
}*/
