/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:29:55 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/11/15 02:58:23 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_pipex(int argc, char *argv[], char *envp[])
{
	int		input;
	int		output;
	int		pipefd[2];
	pid_t	pid;
	int		status;

	if (argc == 5)
	{
		input = openfile(argv[1], IN);
		output = openfile(argv[4], OUT);
		dup2(input, STDIN_FILE);
		dup2(output, STDOUT_FILE);
		pipe(pipefd);
		if (input < 0)
			invalid_msg();
		if (output < 0)
			entry_error();
		pid = fork();
		if (pid == 0)
			child(argv, envp, pipefd);
		waitpid(pid, &status, 0);
		parent(argv, envp, pipefd);
	}
	else
		entry_error();
}

int	main(int argc, char *argv[], char *envp[])
{
	check_arguments(argc, argv);
	exec_pipex(argc, argv, envp);
	return (0);
}
