/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:30:00 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/25 11:17:33 by akhobba          ###   ########.fr       */
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

char	*ft_add_spaces(char *input, int j)
{
	int		i;
	char	*tmp;

	i = ft_count_spaces(input) * 2;
	tmp = malloc(ft_strlen(input) + i + 1);
	i = 0;
	while (input[j])
	{
		if ((input[j] == '<'|| input[j] == '>'|| input[j] == '|') && !check_quote(input, j))
		{
			tmp[i] = ' ';
			tmp[++i] = input[j++];
			if (input[j] == '<'|| input[j] == '>')
			{
				tmp [++i] = input[j++];
			}
			tmp[++i] = ' ';
			i++;
		}
		else
			tmp[i++] = input[j++];
	}
	tmp[i] = '\0';
	return (tmp);
}

char	**ft_lexer(char *input)
{
	char **split_input;
    char *input_spaces;

	input_spaces = ft_add_spaces(input, 0);
	split_input = ft_split(input_spaces, " \n\t\v\f\r");
	free(input_spaces);
	return (split_input);
}