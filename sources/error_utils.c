/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:07:42 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/02/05 17:11:46 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	read_to_eof(int fd)
{
	char	*line;

	if (fd < 3)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->pt)
	{
		i = 0;
		while (i < map->line_nb && map->pt[i])
		{
			free(map->pt[i]);
			i++;
		}
		free(map->pt);
	}
	free(map);
}

void	ft_end_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->init)
	{
		if (mlx->model)
			mlx_destroy_image(mlx->init, mlx->model);
		if (mlx->menu)
			mlx_destroy_image(mlx->init, mlx->menu);
		if (mlx->win)
			mlx_destroy_window(mlx->init, mlx->win);
		mlx_destroy_display(mlx->init);
	}
	ft_free_map(mlx->map);
}

void	ft_error_exit(t_parser *to_free, t_mlx *mlx, char *err)
{
	if (to_free)
	{
		ft_free_map(to_free->map);
		ft_free_array(to_free->array);
		read_to_eof(to_free->fd);
	}
	ft_end_mlx(mlx);
	if (!ft_strncmp(err, "malloc", 7))
		perror(err);
	else if (!ft_strncmp(err, "open", 5))
		perror(err);
	else if (!ft_strncmp(err, "mlx", 4))
		ft_putendl_fd("Macrolibx error", 2);
	else if (!ft_strncmp(err, "nb_col", 7))
		ft_putendl_fd("Error, the map must be rectangular", 2);
	else if (!ft_strncmp(err, "color", 6))
		ft_putendl_fd("Error, color incorrectly formatted", 2);
	else if (!ft_strncmp(err, "height", 7))
		ft_putendl_fd("Error, height incorrectly formatted", 2);
	else if (!ft_strncmp(err, "empty", 6))
		ft_putendl_fd("Error, the map is empty", 2);
	else if (!ft_strncmp(err, "empty line", 11))
		ft_putendl_fd("Error, there is an empty line in the map", 2);
	exit(EXIT_FAILURE);
}
