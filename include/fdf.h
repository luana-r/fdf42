/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:36:37 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/05/29 20:25:25 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include "MLX42/MLX42.h"
#include "libft.h"

# define WIDTH 1280
# define HEIGHT 720
# define PI 3.14159265358979323846

typedef struct s_mesh
{
	int				x;
	int				y;
	int				z;
	struct s_mesh	*next;
}				t_mesh;

typedef struct s_edge
{
	struct s_mesh	vertex_1;
	struct s_mesh	vertex_2;
} t_edge;

typedef struct s_mesh_controller
{
	int	max_z;
	int	min_z;
	int	width;
	int height;
	int	max_x;
	int	max_y;
	t_mesh	*mesh;
	double	scale_factor;
	double	scale_x;
	double	scale_y;
	int		offset_x;
	int		offset_y;
	mlx_t	*mlx;
	mlx_image_t	*img;
}				t_mesh_controller;

typedef struct s_bresenham
{
	int		delta_x;
	int		delta_y;
	int		sign_dx;
	int		sign_dy;
	int		error_1;
	int		error_2;
}	t_bresenham;

typedef struct s_cam
{
	double	scale_factor;
	double	scale_z;
	double	offset_x;
	double	offset_y;
	double	alpha;
	double	gamma;
	double	tetha;
}				t_cam;

void	ft_error(char *error);
void	fdf_file(const char *file_name);
void	ft_gnl_map(const char *file_path, t_mesh **mesh, t_mesh_controller *mesh_data);
t_mesh	*ft_new_point(int x, int y, char *z);
t_mesh	*ft_mesh_last(t_mesh *list);
void	ft_mesh_add_back(t_mesh **mesh, t_mesh *new_point);
void	add_line_data(t_mesh node_1, t_mesh node_2, t_bresenham *line_data);
void	ft_bresenham(t_mesh node_1, t_mesh node_2, t_mesh_controller mesh_data);
void	ft_build_wireframe(t_mesh *mesh, t_mesh_controller *mesh_data);
void	fit_to_window(t_mesh_controller *mesh_data);
void	ft_isometric(t_mesh *mesh, t_mesh_controller *mesh_data);
#endif