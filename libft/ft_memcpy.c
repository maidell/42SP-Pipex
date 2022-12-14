/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 05:16:06 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/07/12 03:26:02 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*mem_src;
	unsigned char	*mem_dest;
	size_t			i;

	if (src == NULL && dest == NULL)
		return (dest);
	i = 0;
	mem_dest = (unsigned char *)dest;
	mem_src = (unsigned char *)src;
	while (n > i)
	{
		mem_dest[i] = mem_src[i];
		i++;
	}
	return (dest);
}
