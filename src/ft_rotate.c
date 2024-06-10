/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:56:42 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/06/09 20:58:43 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_mesh *node_1, t_mesh *node_2, t_fdf_ctl *mesh_data)
{
	int	y;
	int	z;

	y = node_1->y;
	z = node_1->z;
	node_1->y = (cos(mesh_data->alpha) * y) - (sin(mesh_data->alpha) * z);
	node_1->z = (cos(mesh_data->alpha) * z) + (sin(mesh_data->alpha) * y);
	y = node_2->y;
	z = node_2->z;
	node_2->y = (cos(mesh_data->alpha) * y) - (sin(mesh_data->alpha) * z);
	node_2->z = (cos(mesh_data->alpha) * z) + (sin(mesh_data->alpha) * y);
}

void	rotate_y(t_mesh *node_1, t_mesh *node_2, t_fdf_ctl *mesh_data)
{
	int	x;
	int	z;

	x = node_1->x;
	z = node_1->z;
	node_1->x = (cos(mesh_data->gamma) * x) - (sin(mesh_data->gamma) * z);
	node_1->z = (cos(mesh_data->gamma) * z) + (sin(mesh_data->gamma) * x);
	x = node_2->x;
	z = node_2->z;
	node_2->x = (cos(mesh_data->gamma) * x) - (sin(mesh_data->gamma) * z);
	node_2->z = (cos(mesh_data->gamma) * z) + (sin(mesh_data->gamma) * x);
}

void	rotate_z(t_mesh *node_1, t_mesh *node_2, t_fdf_ctl *mesh_data)
{
	int	x;
	int	y;

	x = node_1->x;
	y = node_1->y;
	node_1->x = (cos(mesh_data->tetha) * x) - (sin(mesh_data->tetha) * y);
	node_1->y = (cos(mesh_data->tetha) * y) + (sin(mesh_data->tetha) * x);
	x = node_2->x;
	y = node_2->y;
	node_2->x = (cos(mesh_data->tetha) * x) - (sin(mesh_data->tetha) * y);
	node_2->y = (cos(mesh_data->tetha) * y) + (sin(mesh_data->tetha) * x);
}
