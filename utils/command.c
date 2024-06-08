/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:39:23 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/08 13:04:36 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void  ft_lstadd_back_command(t_command **list, t_command *node)
{
    t_command *tmp;

    if (!list || !node)
        return ;
    if (!*list)
    {
        *list = node;
        return ;
    }
    tmp = *list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
}
t_command *ft_lstnew_command(char *content)
{
    t_command *node;

    node = malloc(sizeof(t_command));
    if (node == NULL)
        return (NULL);
    node->command = content;
    node->next = NULL;
    return (node);
}
void	ft_lstdelone_command(t_command *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstclear_command(t_command **lst)
{
	t_command	*current;
	t_command	*twp;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		twp = current;
		current = current->next;
		ft_lstdelone_command(twp);
	}
	*lst = NULL;
}
void ft_free_command(t_command **command)
{
   if (*command && (*command)->redirection)
            ft_lstclear_redi(&((*command)->redirection));
        if (*command)
            ft_lstclear_command(command);
}