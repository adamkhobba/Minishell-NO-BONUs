/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:54:28 by hichokri          #+#    #+#             */
/*   Updated: 2024/07/22 05:01:04 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// unset bulit-in command
// remove the variable from the environment
// if the variable does not exist, print an error message
// if the variable exists, remove it from the environment
void	unset(char **arg, char **env)
{
	env_store	*tmp;
	env_store	*head;
	env_store	*prev;

	prev = NULL;
	tmp = head;
	head = get_env_value(env);
	while (tmp != NULL)
	{
		if (strcmp(tmp->value, arg[1]) == 0)
		{
			if (prev == NULL && head == NULL)
				head = tmp->next;
			else
				prev->next = tmp->next;
			free_node(tmp);
			prev = tmp;
			tmp = tmp->next;
		}
	}
}
{
	env_store *tmp;
	env_store *head;

	head = get_env_value(env);
	tmp = head;
	while (tmp != NULL)
	{
		if (strcmp(tmp->value, arg[1]) == 0)
		{
			free_node(tmp->value);
			free(tmp);
			return ;
		}
		tmp = tmp->next;
	}
}