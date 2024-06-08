/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:58:49 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/08 08:50:57 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *ft_check_command_path(char *command)
{
     char *path;
     char **split_path;
     char *join_path;
     char *join_path1;
     int i;

     i = 0;
     path = getenv("PATH");
     split_path = ft_split(path, ":");
     while (split_path[i])
     {
          join_path = ft_strjoin(split_path[i], "/");
          join_path1 = ft_strjoin(join_path, command);
          if (access(join_path1, F_OK) == 0)
          {
               ft_free(split_path);
               free(join_path);
               return (join_path1);
          }
          free(join_path);
          free(join_path1);
          i++;
     }
     ft_free(split_path);
     return (NULL);
}

char *ft_check_type(char *command)
{
     char *path;

     if (!ft_strncmp(command, "echo", ft_strlen(command)))
          return (ft_strdup(command));
     else if (!ft_strncmp(command, "export", ft_strlen(command)))
          return (ft_strdup(command));
     else if (!ft_strncmp(command, "unset", ft_strlen(command)))
          return (ft_strdup(command));
     else if (!ft_strncmp(command, "pwd", ft_strlen(command)))
          return (ft_strdup(command));
     else if (!ft_strncmp(command, "env", ft_strlen(command)))
          return (ft_strdup(command));
     else if (!ft_strncmp(command, "cd", ft_strlen(command)))
          return (ft_strdup(command));
     else 
     {
          path = ft_check_command_path(command);
               return(path);
     }
     return (NULL);
}

t_command *ft_check_command(t_link *link)
{
     t_link *tmp;
     char *str;
     t_command *node;
     t_command *command;

     tmp = link;
     command = NULL;
     while (tmp)
     {
          if (tmp && (!tmp->prev || (tmp->prev && tmp->prev->identifer == STR))
               && tmp->identifer == STR)
          {
               str = ft_check_type(tmp->command);
               if (!str)
                    return (NULL);
               node = ft_lstnew_command(str); 
               ft_lstadd_back_command(&command, node); 
               return (command);
          }
               tmp = tmp->next;
     }
     node = ft_lstnew_command(NULL);
     ft_lstadd_back_command(&command, node); 
     return (command);
}

// i shoudl check if the STR is a command or a file for any redirection