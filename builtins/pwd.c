/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:53:00 by hichokri          #+#    #+#             */
/*   Updated: 2024/07/22 04:53:42 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// pwd builtin command
// print the current working directory
// getcwd is used to get the current working directory
void	pwd(void)
{
	char	*cwd;

	char buff[PATH_MAX];
		// buffer to store the path of the current working directory
	cwd = getcwd(buff, PATH_MAX);
	if (cwd != NULL)
		printf("%s\n", cwd);
	else
		perror("Path not found\n");
}
