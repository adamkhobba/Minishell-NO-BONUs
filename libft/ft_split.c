/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:04:15 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/14 10:37:55 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	check;
	size_t	ken;
	size_t	i;

	i = 0;
	ken = 0;
	while (s[i])
	{
		check = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (check == 0)
			{
				ken++;
				check = 1;
			}
			i++;
		}
	}
	return (ken);
}

static int	ft_put_malloc(char **arr, int index, size_t len)
{
	size_t	p;

	p = index;
	arr[index] = (char *)malloc(len);
	if (NULL == arr)
	{
		while (p > 0)
		{
			free(arr[p]);
			p--;
		}
		free(arr);
		return (0);
	}
	return (1);
}

static int	ft_rspl(char **arr, char const *s, char c)
{
	size_t	len;
	size_t	index;
	size_t	size;

	len = 0;
	index = 0;
	size = ft_count_word(s, c);
	while (index < size)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (!ft_put_malloc(arr, index, len + 1))
				return (0);
		}
		ft_strlcpy(arr[index++], s - len, len + 1);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	size;

	if (NULL == s)
		return (NULL);
	size = ft_count_word(s, c);
	arr = (char **)malloc((size + 1) * sizeof(char *));
	if (NULL == arr)
		return (NULL);
	arr[size] = NULL;
	if (!ft_rspl(arr, s, c))
		return (NULL);
	return (arr);
}
/*
int	main(void)
{
	char const	*input;
	char		**result;

 input = "  ada,, kk       hobba   ";
	result = ft_split(input, ' ');
//	printf("%zu\n", ft_count_word(input, ' '));
	for (size_t i = 0; result[i] != NULL; i++)
	{
	printf("%s\n", result[i]);
	free(result[i]);
	}
	free(result); 	
	return (0);
}*/
