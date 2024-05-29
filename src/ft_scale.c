/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:38:21 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/05/22 16:08:25 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fit_to_window(t_mesh_controller *mesh_data)
{
	mesh_data->scale_x = WIDTH / mesh_data->width;
	mesh_data->scale_y = HEIGHT / mesh_data->height;
	if (mesh_data->scale_x <= mesh_data->scale_y)
		mesh_data->scale_factor = mesh_data->scale_x;
	else
		mesh_data->scale_factor = mesh_data->scale_y;
	if (mesh_data->scale_factor < 4)
		mesh_data->scale_factor = 2;
	else
		mesh_data->scale_factor *= 0.5;
}
