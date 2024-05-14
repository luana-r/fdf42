/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:21:51 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/05/14 16:17:07 by lsouza-r         ###   ########.fr       */
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

void	ft_bresenham(t_mesh p1, t_mesh p2, mlx_image_t *img)
{
	t_bresenham	line_data;
	t_mesh	node_1;
	t_mesh	node_2;

	node_1.x = (p1.x - p1.y) * cos(PI/6) + 250;
	node_1.y = (p1.x + p1.y) * sin(PI/6) - p1.z + 250;
	node_2.x = (p2.x - p2.y) * cos(PI/6) + 250;
	node_2.y = (p2.x + p2.y) * sin(PI/6) - p2.z + 250;
	add_line_data(node_1, node_2, &line_data);
	while (1)
	{
		mlx_put_pixel(img, node_1.x, node_1.y, 0xFF0000FF);
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

void	ft_build_wireframe(t_mesh *mesh, t_mesh_controller *mesh_data, mlx_image_t* img)
{
	int	pos_x;
	int	pos_y;
	t_mesh	*bottom_node;
	t_mesh	*current_node;
	int	width;

	ft_isometric(mesh, mesh_data);
	pos_y = 0;
	current_node = mesh;
	while (current_node && current_node->next)
	{
		pos_x = 0;
		while (pos_x < mesh_data->width && current_node && current_node->next)
		{
			if (pos_x < mesh_data->width - 1)
				ft_bresenham(*current_node, *current_node->next, img);
			if (pos_y < mesh_data->height - 1)
			{
				bottom_node = current_node;
				width = 0;
				while (width < mesh_data->width)
				{
					bottom_node = bottom_node->next;
					width++;
				}
				ft_bresenham(*current_node, *bottom_node, img);
			}
		pos_x++;
		current_node = current_node->next;
		}
	pos_y++;
	}
}
