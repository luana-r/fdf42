/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transformations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:00:32 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/05/14 15:09:52 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(t_mesh *mesh, t_mesh_controller *mesh_data)
{
	t_mesh	*current_node;;
	// int	save_x;
	// int	save_y;
	// 
	mesh_data->max_x = 0;
	mesh_data->max_y = 0;
	current_node = mesh;
	// while (current_node != NULL)
	// {
	// 	save_x = current_node->x;
	// 	save_y = current_node->y;
	// 	current_node->x = (save_x - save_y) * cos(PI/6);
	// 	current_node->y = (save_x + save_y) * sin(PI/6) - (current_node->z);
	// 	// if (i->x > mesh_data->max_x)
	// 	// 	mesh_data->max_x = i->x;
	// 	// if (i->y > mesh_data->max_y)
	// 	// 	mesh_data->max_y = i->y;
	// 	current_node = current_node->next;
	// }
	// i = mesh;
	//fit_to_window(mesh_data);
	mesh_data->scale_factor = 20;
// 	i = mesh;
	while (current_node != NULL)
	{
		current_node->x = (current_node->x * mesh_data->scale_factor);
		current_node->y = (current_node->y * mesh_data->scale_factor);
		current_node = current_node->next;
	}
}