/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:35:11 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/11/15 02:46:20 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_arguments(int argc, char **argv)
{
	if (argc != 5)
		msg_error_exit("syntax error: ", "number of invalid arguments\n", 1);
	if (access(argv[1], F_OK))
		msg_error(argv[1], ": No such file or directory\n");
}

void	msg_error_exit(char *str1, char *str2, int exit_code)
{
	msg_error(str1, str2);
	exit(exit_code);
}

void	msg_error(char *str1, char *str2)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
}

void	command_error(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	perror("Command not found");
	exit(127);
}
