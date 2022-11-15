/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:08:41 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/11/15 02:46:44 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *argv, char *envp[])
{
	char	**cmd;
	char	*path;

	cmd_space_substitution(argv);
	cmd = ft_split(argv, ' ');
	cmd_one_substitution (cmd);
	if (cmd[0] == NULL)
	{
		free(cmd[0]);
		free(cmd);
		entry_error();
	}
	path = pathexec(cmd[0], envp);
	if (path == 0)
		command_error(cmd);
	path_error(path, cmd);
	if (execve(path, cmd, envp) == -1)
		entry_error();
}

void	child(char *argv[], char *envp[], int *pipefd)
{
	dup2 (pipefd[OUT], STDOUT_FILE);
	close (pipefd[IN]);
	execute_cmd (argv[2], envp);
}

void	parent(char *argv[], char *envp[], int *pipefd)
{
	dup2(pipefd[IN], STDIN_FILE);
	close(pipefd[OUT]);
	execute_cmd(argv[3], envp);
}
