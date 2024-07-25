/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:39:30 by akhobba           #+#    #+#             */
/*   Updated: 2024/07/25 11:15:01 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_error(void)
{
	t_error	*tmp;

	tmp = g_error;
	while (tmp)
	{
		ft_putstr("minishell: ", 2);
		if (tmp->error == ERROR_QUOTE)
			ft_putstr("quote error\n", 2);
		if (tmp->error == ERROR_COMMAND)
			ft_putstr("command error\n", 2);
		if (tmp->error == ERROR_PIPE)
			ft_putstr("pipe error\n", 2);
		if (tmp->error == ERROR_LESS)
			ft_putstr("in redirection error\n", 2);
		tmp = tmp->next;
	}
	if (!tmp)
		return (0);
	ft_lstclear_error(&g_error);
	return (1);
}
