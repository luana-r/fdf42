/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:56:01 by lsouza-r          #+#    #+#             */
/*   Updated: 2023/12/04 16:55:12 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	c = c % 256;
	len_s = ft_strlen(s);
	while (i <= len_s)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
