/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:36:16 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/02/03 21:49:46 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_mlx *mlx)
{
	mlx->map->x_scale *= 1.25;
	mlx->map->y_scale *= 1.25;
	mlx->map->z_scale *= 1.25;
	mlx->map->x_translate *= 1.25;
	mlx->map->y_translate *= 1.25;
}

void	zoom_out(t_mlx *mlx)
{
	mlx->map->x_scale *= 0.75;
	mlx->map->y_scale *= 0.75;
	mlx->map->z_scale *= 0.75;
	mlx->map->x_translate *= 0.75;
	mlx->map->y_translate *= 0.75;
}

int	zoom_mouse(int event, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	if (event == 1)
		zoom_in(mlx);
	if (event == 2)
		zoom_out(mlx);
	calculate_model(mlx);
	return (0);
}

void	zoom_key(int key, t_mlx *mlx)
{
	if (key == SDL_SCANCODE_EQUALS)
		zoom_in(mlx);
	if (key == SDL_SCANCODE_MINUS)
		zoom_out(mlx);
	calculate_model(mlx);
}

void	scale_z(int key, t_mlx *mlx)
{
	if (key == SDL_SCANCODE_PAGEUP)
		mlx->map->z_scale *= 1.25;
	if (key == SDL_SCANCODE_PAGEDOWN)
		mlx->map->z_scale *= 0.75;
	calculate_model(mlx);
}
