/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:04:58 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/05/29 20:19:42 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void ft_hook(void* param);

static void ft_error_codam(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// void	hook(void *param)
// {
// 	mlx_t	*mlx;

// 	mlx = param;
// 	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
// 		mlx_close_window(param);

static void ft_hook(void *param)
{
	t_mesh_controller	*mesh_data;
	
	mesh_data = param;
	if (mlx_is_key_down(mesh_data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mesh_data->mlx);
	// if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		
	//printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(int argc, char **argv)
{
	t_mesh	*mesh;
	// t_mesh	*i;
	t_mesh_controller mesh_data;
	
	mesh = NULL;
	// i = NULL;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mesh_data.mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!mesh_data.mlx)
		ft_error_codam();
	mesh_data.img = mlx_new_image(mesh_data.mlx, 1280, 720);
	if (!mesh_data.img || (mlx_image_to_window(mesh_data.mlx, mesh_data.img, 0, 0) < 0))
		ft_error_codam();
	if (argc > 2)
		ft_error("Error: Too many arguments :(");
	else if (argc < 2)
		ft_error("Error: You forgot the map :(");
	ft_gnl_map(argv[1], &mesh, &mesh_data);
	ft_build_wireframe(mesh, &mesh_data);
	// mlx_key_hook(mlx, ke, &mesh_data);
	mlx_loop_hook(mesh_data.mlx, ft_hook, &mesh_data);
	mlx_loop(mesh_data.mlx);
	mlx_terminate(mesh_data.mlx);
	return (EXIT_SUCCESS);
}
