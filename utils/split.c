/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:17:34 by adam              #+#    #+#             */
/*   Updated: 2024/05/22 20:11:42 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/minishell.h"


void ft_check_quote(char c, int *q_s, int *q_d)
{
    if (c == '\'')
        *q_s++;
    else if (c == '\"')
        *q_d++;
    if (*q_s > 2)
        *q_s = 0;
    if (*q_d > 2)
        *q_d = 0;
}
static size_t	ft_count_word(char const *s, char c)
{
	size_t	check;
	size_t	ken;
	size_t	i;
    int q_single; 
    int q_double;

	i = 0;
	ken = 0;
    q_double = 0;
    q_single = 0;
	while (s[i])
	{
		check = 0;
        ft_check_quote(s[i], &q_single, &q_double);
		while (s[i] && (q_single == 0 && q_double == 0) && s[i] == c)
        {
            ft_check_quote(s[i], &q_single, &q_double);
            printf("s= %d d = %d\n c =\" %c\"", q_single, q_double, s[i]);
			i++;
        }
		while (s[i] && (q_single == 1 || q_double == 1))
        {
            ft_check_quote(s[i], &q_single, &q_double);
            if (check == 0)
            {
                ken++;
                check = 1;
            }
            i++;
        }
		while (s[i] != c && s[i] && q_single == 0 && q_double == 0)
        {
            ft_check_quote(s[i], &q_single, &q_double);
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
	if (!ft_rspl(arr, s, c))
		return (NULL);
	return (arr);
}

int main ()
{
    char *str = "Hello world \"adam khobba\"";
    char **arr;

    printf("%ld", ft_count_word(str, ' '));
    // arr = ft_split(str, ' ');
    // for (size_t i = 0; arr[i]; i++)
    // {
    //     printf("%s\n", arr[0]);
    // }
    return (0);
}