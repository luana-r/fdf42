/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:04:58 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/05/14 16:12:51 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void ft_error_codam(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	//printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

int32_t	main(int argc, char **argv)
{
	t_mesh	*mesh;
	// t_mesh	*i;
	t_mesh_controller mesh_data;
	
	mesh = NULL;
	// i = NULL;
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "luana", true);
	if (!mlx)
		ft_error_codam();
	mlx_image_t* img = mlx_new_image(mlx, 1200, 900);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error_codam();
	if (argc > 2)
		ft_error("Error: Too many arguments :(");
	else if (argc < 2)
		ft_error("Error: You forgot the map :(");
	ft_gnl_map(argv[1], &mesh, &mesh_data);
	// i = mesh;
	// while (i != NULL)
	// {
	// 	i->x = i->x * 20;
	// 	i->y = i->y * 20;
	// 	i = i->next;
	// }
	// while (mesh != NULL)
	// {
	// 	ft_putnbr_fd((* mesh).x, 1);
	// 	ft_putchar_fd(' ', 1);
	// 	ft_putnbr_fd((* mesh).y, 1);
	// 	ft_putchar_fd(' ', 1);
	// 	ft_putnbr_fd((* mesh).z, 1);
	// 	ft_putchar_fd('\n', 1);
	// 	mesh = mesh->next;
	// }
	ft_build_wireframe(mesh, &mesh_data, img);
	//mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
