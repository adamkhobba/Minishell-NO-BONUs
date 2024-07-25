/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 00:14:54 by akhobba           #+#    #+#             */
/*   Updated: 2024/07/25 11:23:57 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_add_erro(t_errorn errorn)
{
	t_error	*error_node;

	error_node = ft_lstnew_error(errorn);
	ft_lstadd_back_error(&g_error, error_node);
}

int	ft_check_pipes(t_link *link, t_command **command)
{
	t_link		*tmp;
	t_command	*command_tmp;

	command_tmp = *command;
	tmp = link;
	while (tmp)
	{
		if (tmp && tmp->identifer == PIPE)
		{
			if (tmp && tmp->prev && tmp->next)
			{
				tmp = tmp->next;
				ft_check_command(tmp, &command_tmp->next);
				ft_main_checker(tmp, &command_tmp->next);
				break ;
			}
			else
			{
				ft_add_erro(ERROR_PIPE);
				return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
