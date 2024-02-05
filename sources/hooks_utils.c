/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:36:16 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/02/05 17:44:26 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(int key, t_mlx *mlx)
{
	if (key == SDL_SCANCODE_Q)
		mlx->map->z_rot -= 0.1;
	if (key == SDL_SCANCODE_E)
		mlx->map->z_rot += 0.1;
	if (key == SDL_SCANCODE_T)
		mlx->map->x_rot -= 0.1;
	if (key == SDL_SCANCODE_R)
		mlx->map->x_rot += 0.1;
	if (key == SDL_SCANCODE_F)
		mlx->map->y_rot -= 0.1;
	if (key == SDL_SCANCODE_G)
		mlx->map->y_rot += 0.1;
	calculate_model(mlx);
}

void	change_projection(int key, t_mlx *mlx)
{
	if (key == SDL_SCANCODE_P)
		mlx->proj = 'p';
	if (key == SDL_SCANCODE_I)
		mlx->proj = 'i';
	calculate_model(mlx);
}

void	translate_key(int key, t_mlx *mlx)
{
	if (key == SDL_SCANCODE_UP || key == SDL_SCANCODE_S)
		mlx->map->y_translate -= WIN_HEIGHT / 10;
	if (key == SDL_SCANCODE_DOWN || key == SDL_SCANCODE_W)
		mlx->map->y_translate += WIN_HEIGHT / 10;
	if (key == SDL_SCANCODE_LEFT || key == SDL_SCANCODE_D)
		mlx->map->x_translate -= MODEL_WIDTH / 10;
	if (key == SDL_SCANCODE_RIGHT || key == SDL_SCANCODE_A)
		mlx->map->x_translate += MODEL_WIDTH / 10;
	calculate_model(mlx);
}
