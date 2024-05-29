/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transformations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:00:32 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/05/29 20:53:24 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(t_mesh *mesh, t_mesh_controller *mesh_data)
{
	t_mesh	*current_node;
	int		save_x;
	int		save_y;
	
	current_node = mesh;

	mesh_data->offset_x = WIDTH / 3;
	mesh_data->offset_y = HEIGHT / 3;
	while (current_node != NULL)
	{
		current_node->x = (current_node->x * mesh_data->scale_factor);
		current_node->y = (current_node->y * mesh_data->scale_factor);
		save_x = current_node->x;
		save_y = current_node->y;
		current_node->x = (save_x - save_y) * cos(PI/6);
		current_node->y = (save_x + save_y) * sin(PI/6) - (current_node->z);
		current_node->x += mesh_data->offset_x;
		current_node->y += mesh_data->offset_y;
		current_node = current_node->next;
	}
}
