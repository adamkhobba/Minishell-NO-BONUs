/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:17:07 by akhobba           #+#    #+#             */
/*   Updated: 2024/05/20 20:12:26 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*put;
	size_t	i;

	i = 0;
	ptr = (char *)s;
	put = (char *)malloc(ft_strlen(s) + 1);
	if (put == NULL)
		return (0);
	while (ptr[i])
	{
		put[i] = ptr[i];
		i++;
	}
	put[i] = '\0';
	return (put);
}

char	**ft_strdup_pro(char **s)
{
	char	**ptr;
	char	**put;
	int		size;
	size_t	i;

	i = 0;
	ptr = s;
	size = ft_count_strs(ptr);
	put = malloc(sizeof(char *) * (size + 1));
	if (!put)
		return (0);
	while (ptr[i])
	{
		put[i] = ft_strdup(ptr[i]);
		i++;
	}
	put[i] = NULL;
	return (put);
}
