/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 05:16:01 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/07/12 03:25:55 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*usgn_str;
	unsigned char	usgn_c;
	size_t			i;

	usgn_str = (unsigned char *) str;
	usgn_c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (usgn_c == usgn_str[i])
			return ((void *)usgn_str + i);
		i++;
	}
	return (NULL);
}
