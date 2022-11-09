/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 05:16:11 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/07/12 03:26:09 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	counter;
	unsigned char	*usgn_str;

	usgn_str = (unsigned char *)str;
	counter = 0;
	while (counter < n)
	{
		usgn_str[counter] = c;
		counter++;
	}
	return (str);
}
