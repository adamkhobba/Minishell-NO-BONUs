/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:19:35 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/12 16:59:43 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*
void	fupeer(unsigned int i, char *c)
{
	if(*c >= 97 && *c <= 122)
			*c = *c - 32;
}

int	main(void)
{
	char input[] = "Hello, World!";
	printf("Original: %s\n", input);

	ft_striteri(input, &fupeer);
	printf("Modified: %s\n", input);

	return (0);
}*/
