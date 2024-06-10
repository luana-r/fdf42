/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transformations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:00:32 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/06/09 20:57:28 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(t_mesh *node_1, t_mesh *node_2)
{
	int	save_x;
	int	save_y;

	save_x = node_1->x;
	save_y = node_1->y;
	node_1->x = (save_x - save_y) * cos(PI / 6);
	node_1->y = (save_x + save_y) * sin(PI / 6) - (node_1->z);
	save_x = node_2->x;
	save_y = node_2->y;
	node_2->x = (save_x - save_y) * cos(PI / 6);
	node_2->y = (save_x + save_y) * sin(PI / 6) - (node_2->z);
}

void	scale(t_mesh *node_1, t_mesh *node_2, t_fdf_ctl *mesh_data)
{
	node_1->x = (node_1->x * mesh_data->scale_factor);
	node_1->y = (node_1->y * mesh_data->scale_factor);
	node_2->x = (node_2->x * mesh_data->scale_factor);
	node_2->y = (node_2->y * mesh_data->scale_factor);
}

void	translate(t_mesh *node_1, t_mesh *node_2, t_fdf_ctl *mesh_data)
{
	node_1->x += mesh_data->offset_x;
	node_1->y += mesh_data->offset_y;
	node_2->x += mesh_data->offset_x;
	node_2->y += mesh_data->offset_y;
}

void	centralize(t_mesh *node_1, t_mesh *node_2, t_fdf_ctl *mesh_data)
{
	node_1->x -= mesh_data->width / 2;
	node_1->y -= mesh_data->height / 2;
	node_2->x -= mesh_data->width / 2;
	node_2->y -= mesh_data->height / 2;
}
