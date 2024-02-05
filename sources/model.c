/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:19:25 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/02/05 17:14:58 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_mlx mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < MODEL_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT)
		{
			mlx_set_image_pixel(mlx.init, mlx.model, i, j, 0);
			j++;
		}
		i++;
	}
}

void	apply_projection(int *x, int *y, int z, char proj)
{
	if (proj == 'i')
		apply_isometric(x, y, z);
}

void	calculate_point_model(t_pt *pt, t_mlx *mlx)
{
	int	x;
	int	y;
	int	z;

	x = pt->x;
	y = pt->y;
	z = pt->z;
	apply_scale(&x, &y, &z, mlx->map);
	apply_rotation(&x, &y, &z, mlx->map);
	apply_projection(&x, &y, z, mlx->proj);
	apply_translation(&x, &y, mlx->map);
	pt->x_proj = x;
	pt->y_proj = y;
}

void	calculate_model(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map->line_nb)
	{
		j = 0;
		while (j < mlx->map->col_nb)
		{
			calculate_point_model(&mlx->map->pt[i][j], mlx);
			j++;
		}
		i++;
	}
	clear_image(*mlx);
	draw_map(mlx);
}

void	draw_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map->line_nb)
	{
		j = 0;
		while (j < mlx->map->col_nb)
		{
			if (j + 1 < mlx->map->col_nb)
				draw_line(mlx->map->pt[i][j], mlx->map->pt[i][j + 1], *mlx);
			if (i + 1 < mlx->map->line_nb)
				draw_line(mlx->map->pt[i][j], mlx->map->pt[i + 1][j], *mlx);
			j++;
		}
		i++;
	}
}
