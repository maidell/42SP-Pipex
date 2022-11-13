/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:08:41 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/11/13 05:35:57 by mmaidel-         ###   ########.fr       */
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

//void exec_pipe (int argc, char *argv[], char *envp[])
// {
// int		input;
// 	int		output;
// 	int		pipefd[2];
// 	pid_t	pid;
// 	int		status;

// 	if (argc == 5)
// 	{
// 		input = openfile(argv[1], IN);
// 		output = openfile(argv[4], OUT);
// 		dup2(input, STDIN_FILE);
// 		dup2(output, STDOUT_FILE);
// 		pipe (pipefd);
// 		if (input < 0)
// 			invalid_msg();
// 		if (output < 0)
// 			entry_error();
// 		pid = fork();
// 		if (pid == 0)
// 			child(argv, envp, pipefd);
// 		waitpid(pid, &status, 0);
// 		parent(argv, envp, pipefd);
// 	}
// 	else
// 		entry_error();
// }

