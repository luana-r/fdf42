/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:25:02 by lsouza-r          #+#    #+#             */
/*   Updated: 2023/12/28 17:35:14 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long int n)
{
	size_t	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char			*str_save;
	int				digits;
	long long		num;

	num = n;
	if (num < 0)
		num = num * -1;
	digits = count_digits(num);
	if (n < 0)
		digits++;
	str_save = (char *) malloc((digits + 1) * sizeof(char));
	if (!str_save)
		return (NULL);
	str_save[digits] = '\0';
	if (n == 0)
		str_save[0] = '0';
	if (n < 0)
		str_save[0] = '-';
	while (num > 0)
	{
		str_save[digits - 1] = (num % 10) + '0';
		num = num / 10;
		digits--;
	}
	return (str_save);
}
