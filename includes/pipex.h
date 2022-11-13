/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:30:03 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/11/13 05:47:21 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERROR 1
# define IN 0
# define OUT 1
# define STDOUT_FILE 1
# define STDIN_FILE 0

void	execute_cmd(char *argv, char *envp[]);
void	child(char *argv[], char *envp[], int *pipefd);
void	parent(char *argv[], char *envp[], int *pipefd);
void	exec_pipe(int argc, char *argv[], char *envp[]);

void	*pathexec(char *cmd, char *envp[]);
char	*cmd_space_substitution(char *argv);
char	**cmd_one_substitution(char **cmd);
void	one_substitution_2(char **cmd, int i, int x);
void	path_error(char *path, char **cmd);

void	msg_error(char *str1, char *str2);
int		msg_error2(char *err);

void	entry_error(void);
void	msg_error_exit(char *str1, char *str2, int exit_code);
void	check_arguments(int argc, char **argv);
void	invalid_msg(void);
void	command_error(char **cmd);

int		openfile(char *filename, int mode);

#endif