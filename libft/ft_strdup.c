/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 05:16:29 by mmaidel-          #+#    #+#             */
/*   Updated: 2022/07/12 03:26:27 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str_dst;
	int		s_len;

	s_len = ft_strlen(s) + 1;
	str_dst = malloc(s_len);
	if (!str_dst)
		return (NULL);
	ft_strlcpy(str_dst, s, s_len);
	return (str_dst);
}
