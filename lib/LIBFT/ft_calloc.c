/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:47:10 by lsouza-r          #+#    #+#             */
/*   Updated: 2023/12/05 21:27:38 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*save;

	if ((size * nmemb != 0) && (nmemb * size) / size != nmemb)
		return (0);
	save = malloc (nmemb * size);
	if (save != 0)
		ft_bzero(save, nmemb * size);
	return (save);
}
