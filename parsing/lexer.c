/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:30:00 by akhobba           #+#    #+#             */
/*   Updated: 2024/05/29 09:52:09 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_count_spaces(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '<' || input[i] == '>' || input[i] == '|')
			count++;
		if ( input[i + 1] && ((input[i] == '<' && input[i + 1] == '<')
			|| (input[i] == '>' && input[i + 1] == '>')))
			count--;
		i++;
	}
	return (count);
}

char	*ft_add_spaces(char *input)
{
	int		i;
	int		j;
	char	*tmp;
	int		size_plus;

	size_plus = ft_count_spaces(input) * 2;
	tmp = malloc(ft_strlen(input) + size_plus + 1);
	i = 0;
	j = 0;
	while (input[j])
	{
		if ((input[j] == '<' && input[i + 1] != '<') || (input[i] == '>'
				&& input[j + 1] != '>') || input[i] == '|')
		{
        	tmp[i] = ' ';
        	tmp[i + 1] = input[j];
        	tmp[i + 2] = ' ';
			i += 2;
		}
		else if ((input[j] == '<' && input[i + 1] == '<') || (input[i] == '>'
				&& input[j + 1] == '>'))
		{
        	tmp[i] = ' ';
        	tmp[i + 1]= input[j];
        	tmp[i + 2] = input[j + 1];
        	tmp[i + 3] = ' ';
			i += 3;
			j++;
		}
		else
		{
			tmp[i] = input[j];
			i++;
		}
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	**ft_lexer(char *input)
{
	char **split_input;
    char *input_spaces;

	input_spaces = ft_add_spaces(input);
	split_input = ft_split(input_spaces, ' ');
	free(input_spaces);
	return (split_input);
}