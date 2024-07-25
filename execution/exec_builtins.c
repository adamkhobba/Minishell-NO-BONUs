
#include "../include/minishell.h"

// step 1: check if it's a builtin
int	is_builtin(t_command *cmd)
{
	if (ft_strcmp(cmd->cmd_args[0], "echo") == 0)
		return (1);
	if (ft_strcmp(cmd->cmd_args[0], "cd") == 0)
		return (1);
	if (ft_strcmp(cmd->cmd_args[0], "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd->cmd_args[0], "exit") == 0)
		return (1);
	if (ft_strcmp(cmd->cmd_args[0], "unset") == 0)
		return (1);
	if (ft_strcmp(cmd->cmd_args[0], "env") == 0)
		return (1);
	else
		return (0);
}
// step 2 check if it's a single command then execute it directly without forking
