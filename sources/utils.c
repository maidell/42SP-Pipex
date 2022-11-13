/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:35:07 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/11/13 04:34:53 by mmaidel-         ###   ########.fr       */
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