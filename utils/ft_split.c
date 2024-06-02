/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:17:34 by adam              #+#    #+#             */
/*   Updated: 2024/06/02 08:38:02 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_quote(char *str, int a)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			j = i + 1;
			while (str[j] && str[j] != str[i])
				j++;
			if (j == ft_strlen(str))
				return (0);
			if (a > i && a < j)
				return (1);
			i = j + 1;
		}
		else
			i++;
	}
	return (0);
}

static size_t	ft_count_word(char *s, char c)
{
	size_t	check;
	size_t	ken;
	size_t	i;

	i = 0;
	ken = 0;
	while (s[i])
	{
		check = 0;
		while (s[i] && s[i] == c && !check_quote(s, i))
			i++;
		while (s[i] && (s[i] != c || (s[i] == c && check_quote(s, i))))
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

static int	ft_rspl(char **arr, char *s, char c, int size)
{
	size_t	len;
	int	index;
	int		i;

	i = 0;
	index = 0;
	while (index < size)
	{
		len = 0;
		while (s[i] && s[i] == c && !check_quote(s, i))
			i++;
		while (s[i] && (s[i] != c || (s[i] == c && check_quote(s, i))))
		{
			len++;
			i++;
		}
		if (len)
		{
			if (!ft_put_malloc(arr, index, len + 1))
				return (0);
		}
		ft_strlcpy(arr[index++], s + (i - len), len + 1);
	}
	return (1);
}

char	**ft_split(char *s, char c)
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
	if (!ft_rspl(arr, s, c, size))
		return (NULL);
	return (arr);
}