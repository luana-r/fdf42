/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:10:32 by lsouza-r          #+#    #+#             */
/*   Updated: 2023/12/06 16:26:16 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*save;
	int		i;
	int		len_s;

	i = 0;
	len_s = ft_strlen(s) + 1;
	save = (char *)malloc (len_s * sizeof(char));
	if (save == 0)
		return (0);
	while (s[i])
	{
		save[i] = s[i];
		i++;
	}
	save[i] = '\0';
	return (save);
}
