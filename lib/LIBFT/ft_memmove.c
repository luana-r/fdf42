/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:31:57 by lsouza-r          #+#    #+#             */
/*   Updated: 2023/12/28 17:40:54 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pnt_src;
	unsigned char	*pnt_dest;

	pnt_src = (unsigned char *)src;
	pnt_dest = (unsigned char *)dest;
	if (!pnt_src && !pnt_dest)
		return (NULL);
	else if (dest < src)
		return (ft_memcpy(dest, src, n));
	else if (n > 0)
		while (n--)
			pnt_dest[n] = pnt_src[n];
	return (dest);
}
