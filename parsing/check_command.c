/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:58:49 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/02 08:38:40 by adam             ###   ########.fr       */
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
     split_path = ft_split(path, ':');
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

     if (!ft_strncmp(command, "ls", ft_strlen(command)))
          return (ft_strdup(command));
     else if (!ft_strncmp(command, "echo", ft_strlen(command)))
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
     t_command *command;

     tmp = link;
     while (tmp)
     {
          while (tmp)
          {
               if (tmp->identifer == STR)
                    break; 
               tmp = tmp->next;
          }
          if (!tmp)
               return (NULL);
          command->command = ft_check_type(tmp->command);
          if (!command->command)
          {
               ft_putstr("minishell: command not found: ", 2);
               ft_putstr(tmp->command, 2);
               return (NULL);
          }
               tmp = tmp->next;
               command = command->next;
     }
        return (command);
}
