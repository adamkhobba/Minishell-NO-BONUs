/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:40:03 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/25 19:36:04 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"
 

t_error *error;

int main() {
    char *input;
    t_command *command;

    command = NULL;
    error = NULL;
    while (1)
    {
        input = readline("minishell>");
        if (input)
            add_history(input);
        if (ft_strncmp(input, "exit", 4) == 0)
        {
            free(input);
            break;
        }
        command = ft_parser(input);
        if (!ft_error())
            continue;
        t_command *tmp = command;
        int i;
        while (tmp)
        {
            printf("command=%s\n", tmp->command);
            i = 0;
            if (tmp->args)
            while (tmp->args[i])
            {
                printf("args=%s\n", tmp->args[i]);
                i++;
            }
            t_redirection *t = tmp->redirection;
            while (t)
            {
                printf("file=%s id=%d\n", tmp->redirection->file,
                    t->identifer);
                    t= t->next;
            }
            tmp = tmp->next;
        } 
        ft_free_command(&command); 
        free(input);
    }
    ft_free_command(&command); 
    return 0;
}