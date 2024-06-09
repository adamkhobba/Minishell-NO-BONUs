/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:40:03 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/09 22:00:21 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"
 

t_error **error;

int main() {
    char *input;
    t_command *command;

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
        t_command *tmp = command;
        while (tmp)
        {
            printf("command=%s\n", tmp->command);
            while (tmp->redirection)
            {
                printf("file=%s id=%d\n", tmp->redirection->file,
                    tmp->redirection->identifer);
                    tmp->redirection = tmp->redirection->next;
            }
            tmp = tmp->next;
        } 
        ft_free(command->args);
        ft_free_command(&command); 
        free(input);
        ft_free(split_input); // lost of leaks address
    }
    ft_free_command(&command); 
    return 0;
}