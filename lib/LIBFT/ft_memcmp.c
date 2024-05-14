/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:53:53 by lsouza-r          #+#    #+#             */
/*   Updated: 2023/12/06 16:25:56 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*char_s1;
	unsigned const char	*char_s2;
	size_t				i;

	i = 0;
	char_s1 = s1;
	char_s2 = s2;
	if ((!s1 && !s2) || n == 0)
		return (0);
	while (i < n - 1)
	{
		if (char_s1[i] == char_s2[i])
			i++;
		else
			return (char_s1[i] - char_s2[i]);
	}
	return (char_s1[i] - char_s2[i]);
}
