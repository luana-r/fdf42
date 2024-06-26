/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:38:23 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/06/09 21:11:54 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf_data(t_fdf_ctl *mesh_data)
{
	mesh_data->width = 0;
	mesh_data->max_z = 0;
	mesh_data->min_z = 0;
	mesh_data->alpha = 0.955323419;
	mesh_data->gamma = 0;
	mesh_data->tetha = 0.785398;
	mesh_data->offset_x = WIDTH / 2;
	mesh_data->offset_y = HEIGHT / 2;
}
