/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 05:16:41 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/07/12 03:26:35 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	counter;

	counter = 0;
	if (!dest || !src)
		return (0);
	if (size)
	{	
		while (src[counter] && counter < (size - 1))
		{
			dest[counter] = src[counter];
			counter++;
		}
		dest[counter] = '\0';
	}
	return (ft_strlen(src));
}
