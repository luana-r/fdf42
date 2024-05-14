/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:51:58 by lsouza-r          #+#    #+#             */
/*   Updated: 2023/12/28 17:20:21 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	is_neg;
	int	num_int;

	i = 0;
	num_int = 0;
	is_neg = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			is_neg = 1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58 && nptr[i] != '\0')
	{
		num_int = (10 * num_int) + ((unsigned char)(nptr[i]) - '0');
		i++;
	}
	if (is_neg)
		num_int = -num_int;
	return (num_int);
}
