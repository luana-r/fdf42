/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:37:23 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/05/22 16:03:25 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mesh	*ft_mesh_last(t_mesh *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

void	ft_mesh_add_back(t_mesh **mesh, t_mesh *new_point)
{
	t_mesh	*last_point;

	if (!*mesh)
	{
		*mesh = new_point;
		return ;
	}
	last_point = ft_mesh_last(*mesh);
	last_point->next = new_point;
}

t_mesh	*ft_new_point(int x, int y, char *z)
{
	t_mesh	*new_point;

	new_point = malloc(sizeof(t_mesh));
	if (!new_point)
		return (NULL);
	new_point->x = x;
	new_point->y = y;
	new_point->z = ft_atoi(z);
	new_point->next = NULL;
	return (new_point);
}

void	fdf_file(const char *file_name)
{
	int str_len;

	str_len = ft_strlen(file_name);
	if (ft_strncmp(&file_name[str_len - 4], ".fdf", 4) != 0)
		ft_error("File is not fdf type.");
}

void	ft_gnl_map(const char *file_path, t_mesh **mesh, t_mesh_controller *mesh_data)
{
	int		fd;
	char	*line;
	char	**splitted;
	int		x;
	int		y;
	
	fdf_file(file_path);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_error("Failed to open the map.");
	line = get_next_line(fd);
	y = 0;
	mesh_data->width = 0;
	mesh_data->max_z = 0;
	mesh_data->min_z = 0;
	while (line)
	{
		splitted = ft_split(line, ' ');
		x = 0;
		while(splitted[x] != NULL)
		{
			ft_mesh_add_back(mesh, ft_new_point(x, y, splitted[x]));
			if (ft_atoi(splitted[x]) > mesh_data->max_z)
				mesh_data->max_z = ft_atoi(splitted[x]);
			if (ft_atoi(splitted[x]) < mesh_data->min_z)
				mesh_data->min_z = ft_atoi(splitted[x]);
			x++;
		}
		if (y == 0)
			mesh_data->width = x;
		else if (mesh_data->width != x)
			ft_error("Error: All lines must have the same number of points. ");
		else
			mesh_data->width = x;
		free (line);
		free (splitted);
		line = get_next_line(fd);
		y++;
	}
	if (y < 2)
		ft_error("Error: The map needs at least two lines.");
	else
		mesh_data->height = y;
	close(fd);
} 
