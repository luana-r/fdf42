/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:21:51 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/06/09 20:47:12 by lsouza-r         ###   ########.fr       */
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
	if (node_1.z >= node_2.z)
		line_data->color_rgba = node_1.color_rgba;
	else
		line_data->color_rgba = node_2.color_rgba;
}

void	ft_bresenham(t_mesh n_1, t_mesh n_2, t_fdf_ctl *mesh_data)
{
	t_bresenham	line_data;

	add_line_data(n_1, n_2, &line_data);
	while (1)
	{
		if (n_1.x >= 0 && n_1.x < WIDTH && n_1.y >= 0 && n_1.y < HEIGHT)
			mlx_put_pixel(mesh_data->img, n_1.x, n_1.y, line_data.color_rgba);
		if (n_1.x == n_2.x && n_1.y == n_2.y)
			break ;
		line_data.error_2 = 2 * line_data.error_1;
		if (line_data.error_2 >= line_data.delta_y)
		{
			if (n_1.x == n_2.x)
				break ;
			line_data.error_1 += line_data.delta_y;
			n_1.x += line_data.sign_dx;
		}
		if (line_data.error_2 <= line_data.delta_x)
		{
			if (n_1.y == n_2.y)
				break ;
			line_data.error_1 += line_data.delta_x;
			n_1.y += line_data.sign_dy;
		}
	}
}

void	ft_draw_edge(t_mesh node_1, t_mesh node_2, t_fdf_ctl *mesh_data)
{
	t_mesh	vertex_1;
	t_mesh	vertex_2;

	vertex_1 = node_1;
	vertex_2 = node_2;
	centralize(&vertex_1, &vertex_2, mesh_data);
	scale(&vertex_1, &vertex_2, mesh_data);
	rotate_z(&vertex_1, &vertex_2, mesh_data);
	rotate_x(&vertex_1, &vertex_2, mesh_data);
	rotate_y(&vertex_1, &vertex_2, mesh_data);
	translate(&vertex_1, &vertex_2, mesh_data);
	ft_bresenham(vertex_1, vertex_2, mesh_data);
}

void	draw_vertical_line(t_mesh *current_node, t_fdf_ctl *mesh_data)
{
	int		iter_list;
	t_mesh	*bottom_node;

	bottom_node = current_node;
	iter_list = 0;
	while (iter_list < mesh_data->width)
	{
		bottom_node = bottom_node->next;
		iter_list++;
	}
	ft_draw_edge(*current_node, *bottom_node, mesh_data);
}

void	ft_build_wireframe(t_mesh *mesh, t_fdf_ctl *mesh_data)
{
	int		pos_x;
	int		pos_y;
	t_mesh	*current_node;

	pos_y = 0;
	current_node = mesh;
	while (current_node && current_node->next)
	{
		pos_x = 0;
		while (pos_x < mesh_data->width && current_node && current_node->next)
		{
			if (pos_x < mesh_data->width - 1)
				ft_draw_edge(*current_node, *current_node->next, mesh_data);
			if (pos_y < mesh_data->height - 1)
				draw_vertical_line(current_node, mesh_data);
		pos_x++;
		current_node = current_node->next;
		}
	pos_y++;
	}
}
