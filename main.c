/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:40:03 by akhobba           #+#    #+#             */
/*   Updated: 2024/07/25 11:55:24 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

t_error	*g_error;

int	main(void)
{
	char			*input;
	t_command		*command;
	t_command		*tmp;
	int				i;
	t_redirection	*t;

	command = NULL;
	g_error = NULL;
	while (1)
	{
		input = readline("minishell>");
		if (input)
			add_history(input);
		if (ft_strncmp(input, "exit", 4) == 0)
		{
			free(input);
			break ;
		}
		command = ft_parser(input);
		if (!ft_error())
			continue ;
		tmp = command;
		printf("command=%s\n", command->command);
		while (tmp)
		{
			printf("command=%s\n", tmp->command);
			i = 0;
			if (tmp->args)
			{
				while (tmp->args[i])
				{
					printf("args=%s\n", tmp->args[i]);
					i++;
				}
			}
			t = tmp->redirection;
			while (t)
			{
				printf("file=%s id=%d\n", t->file, t->identifer);
				t = t->next;
			}
			tmp = tmp->next;
		}
		ft_free_command(&command);
		free(input);
	}
	ft_free_command(&command);
	return (0);
}
