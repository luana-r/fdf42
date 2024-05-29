/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:21:51 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/05/29 20:54:41 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_line_data(t_mesh node_1, t_mesh node_2, t_bresenham *line_data)
{
	line_data->delta_x = abs(node_2.x - node_1.x);
	line_data->delta_y = -abs(node_2.y - node_1.y);
	if (node_1.x < node_2.x)
		line_data->sign_dx = 1;
	else 
		line_data->sign_dx = -1;
	if (node_1.y < node_2.y)
		line_data->sign_dy = 1;
	else
		line_data->sign_dy = -1;
	line_data->error_1 = line_data->delta_x + line_data->delta_y;
}

void	ft_bresenham(t_mesh node_1, t_mesh node_2, t_mesh_controller mesh_data)
{
	t_bresenham	line_data;

	add_line_data(node_1, node_2, &line_data);
	while (1)
	{
		if (node_1.x >= 0 && node_1.x < WIDTH && node_1.y >= 0 && node_1.y < HEIGHT)
		mlx_put_pixel(mesh_data.img, node_1.x, node_1.y, 0xFF0000FF);
		if (node_1.x == node_2.x && node_1.y == node_2.y)
			break;
		line_data.error_2 = 2 * line_data.error_1;
		if (line_data.error_2 >= line_data.delta_y)
		{
			if (node_1.x == node_2.x)
				break;
			line_data.error_1 += line_data.delta_y;
			node_1.x += line_data.sign_dx;
		}
		if (line_data.error_2 <= line_data.delta_x)
		{
			if (node_1.y == node_2.y)
				break ;
			line_data.error_1 += line_data.delta_x;
			node_1.y += line_data.sign_dy;
		}
	}
}

// void	raster_line(t_mesh node_1, t_mesh node_2, t_mesh_controller *mesh_data, mlx_image_t* img)
// {
// 	t_edge edge;

// 	edge.vertex_1 = node_1;
// 	edge.vertex_2 = node_2;
// 	rotate(edge, mesh_data);
// 	project(edge, mesh_data);
// 	scale(edge, mesh_data);
// 	translate(edge, mesh_data);
// }


void	ft_build_wireframe(t_mesh *mesh, t_mesh_controller *mesh_data)
{
	int	pos_x;
	int	pos_y;
	t_mesh	*bottom_node;
	t_mesh	*current_node;
	int	width;
	// t_cam	*cam;

	fit_to_window(mesh_data);
	ft_isometric(mesh, mesh_data);
	//init_cam(cam);
	pos_y = 0;
	current_node = mesh;
	while (current_node && current_node->next)
	{
		pos_x = 0;
		while (pos_x < mesh_data->width && current_node && current_node->next)
		{
			if (pos_x < mesh_data->width - 1)
				ft_bresenham(*current_node, *current_node->next, *mesh_data);
			if (pos_y < mesh_data->height - 1)
			{
				bottom_node = current_node;
				width = 0;
				while (width < mesh_data->width)
				{
					bottom_node = bottom_node->next;
					width++;
				}
				ft_bresenham(*current_node, *bottom_node, *mesh_data);
			}
		pos_x++;
		current_node = current_node->next;
		}
	pos_y++;
	}
}
