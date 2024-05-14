/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:38:58 by lsouza-r          #+#    #+#             */
/*   Updated: 2023/12/13 13:28:32 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len_all;

	len_all = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (s1[0] == '\0' && s2[0] == '\0')
		return (ft_strdup(""));
	s = (char *)malloc ((len_all) * sizeof(char));
	if (s == NULL)
		return (NULL);
	ft_strlcpy(s, s1, len_all);
	ft_strlcat(s, s2, len_all);
	return (s);
}
