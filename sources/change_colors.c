/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:22:42 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/02/04 23:18:34 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	sea_color(int z, int z_min)
{
	double	ratio;
	double	scale;
	double	position;
	int		color;

	scale = abs(z_min);
	position = abs(z_min) - abs(z);
	ratio = position / scale;
	color = get_radient(ratio, COLOR_NAVY, COLOR_TEAL);
	return (color);
}

int	earth_color(int z, int z_max)
{
	double	ratio;
	int		color;

	if (z_max)
		ratio = (double) z / (double) z_max;
	else
		ratio = 0;
	color = get_radient(ratio, COLOR_GRASS, COLOR_MAROON);
	return (color);
}

void	change_colors(t_mlx *mlx)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	while (i < mlx->map->line_nb)
	{
		j = 0;
		while (j < mlx->map->col_nb)
		{
			z = mlx->map->pt[i][j].z;
			if (z < 0)
				mlx->map->pt[i][j].color = sea_color(z, mlx->map->z_min);
			else
				mlx->map->pt[i][j].color = earth_color(z, mlx->map->z_max);
			j++;
		}
		i++;
	}
	draw_map(mlx);
}

void	reset_colors(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map->line_nb)
	{
		j = 0;
		while (j < mlx->map->col_nb)
		{
			mlx->map->pt[i][j].color = mlx->map->pt[i][j].file_color;
			j++;
		}
		i++;
	}
	draw_map(mlx);
}
