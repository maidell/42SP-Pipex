/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:35:07 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/11/15 02:46:25 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile(char *filename, int mode)
{
	if (mode == IN)
	{
		if (access(filename, F_OK))
		{
			perror(" ");
			exit(ERROR);
		}
		return (open(filename, O_RDONLY, 0644));
	}
	else
		return (open(filename, O_TRUNC | O_CREAT | O_RDWR, 0644));
}

int	msg_error2(char *err)
{
	perror(err);
	exit(ERROR);
}

void	invalid_msg(void)
{
	ft_putstr_fd("Permission denied\n", 2);
	exit(0);
}

void	entry_error(void)
{
	int		argc;
	char	**argv;

	check_arguments(argc, argv);
}