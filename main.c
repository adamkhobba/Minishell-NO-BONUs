/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:40:03 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/25 09:50:06 by akhobba          ###   ########.fr       */
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
        if (input == NULL) {
         printf("\nError reading input. Exiting...\n");
            exit(EXIT_FAILURE);
        }
        if (ft_strncmp(input, "exit", 4) == 0)
        {
            free(input);
            break;
        }
        command = ft_parser(input);
        ft_error();
        // t_command *tmp = command;
        // int i;
        // while (tmp)
        // {
        //     printf("command=%s\n", tmp->command);
        //     i = 0;
        //     if (tmp->args)
        //     while (tmp->args[i])
        //     {
        //         printf("args=%s\n", tmp->args[i]);
        //         i++;
        //     }
        //     while (tmp->redirection)
        //     {
        //         printf("file=%s id=%d\n", tmp->redirection->file,
        //             tmp->redirection->identifer);
        //             tmp->redirection = tmp->redirection->next;
        //     }
        //     tmp = tmp->next;
        // } 
        // ft_free_command(&command); 
        free(input);
    }
    ft_free_command(&command); 
    return 0;
}