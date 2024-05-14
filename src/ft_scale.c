/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:38:21 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/05/06 20:30:52 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fit_to_window(t_mesh_controller *mesh_data)
{
	float	scale_x;
	float	scale_y;
	
	scale_x = WIDTH / mesh_data->max_x;
	scale_y = HEIGHT / mesh_data->max_y;
	if (scale_x <= scale_y)
		mesh_data->scale_factor = scale_x;
	else
		mesh_data->scale_factor = scale_y;
}
