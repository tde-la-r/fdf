/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:58:00 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/02/05 17:43:48 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	if (key == SDL_SCANCODE_PAGEDOWN || key == SDL_SCANCODE_PAGEUP)
		scale_z(key, mlx);
	if (key == SDL_SCANCODE_EQUALS || key == SDL_SCANCODE_MINUS)
		zoom_key(key, mlx);
	if (key == SDL_SCANCODE_Q || key == SDL_SCANCODE_E \
			|| key == SDL_SCANCODE_R || key == SDL_SCANCODE_T \
			|| key == SDL_SCANCODE_F || key == SDL_SCANCODE_G)
		rotate(key, mlx);
	if (key == SDL_SCANCODE_P || key == SDL_SCANCODE_I)
		change_projection(key, mlx);
	if (key == SDL_SCANCODE_UP || key == SDL_SCANCODE_DOWN \
			|| key == SDL_SCANCODE_LEFT || key == SDL_SCANCODE_RIGHT \
			|| key == SDL_SCANCODE_W || key == SDL_SCANCODE_A \
			|| key == SDL_SCANCODE_S || key == SDL_SCANCODE_D)
		translate_key(key, mlx);
	if (key == SDL_SCANCODE_C)
		change_colors(mlx);
	if (key == SDL_SCANCODE_X)
		reset_colors(mlx);
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(mlx->init);
	return (0);
}

int	win_hook(int event, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	if (event == 0)
		mlx_loop_end(mlx->init);
	return (0);
}

int	mouse_up_hook(int event, void *param)
{
	t_mlx	*mlx;
	int		x_msup;
	int		y_msup;

	mlx = (t_mlx *) param;
	if (event == 1)
	{
		mlx_mouse_get_pos(mlx->init, &x_msup, &y_msup);
		mlx->map->x_translate += x_msup - mlx->x_mouse;
		mlx->map->y_translate += y_msup - mlx->y_mouse;
		calculate_model(mlx);
	}
	return (0);
}

int	mouse_dn_hook(int event, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	if (event == 1)
		mlx_mouse_get_pos(mlx->init, &mlx->x_mouse, &mlx->y_mouse);
	return (0);
}

void	hooks_mlx(t_mlx *mlx)
{
	mlx_on_event(mlx->init, mlx->win, MLX_KEYDOWN, key_hook, mlx);
	mlx_on_event(mlx->init, mlx->win, MLX_MOUSEDOWN, mouse_dn_hook, mlx);
	mlx_on_event(mlx->init, mlx->win, MLX_MOUSEUP, mouse_up_hook, mlx);
	mlx_on_event(mlx->init, mlx->win, MLX_MOUSEWHEEL, zoom_mouse, mlx);
	mlx_on_event(mlx->init, mlx->win, MLX_WINDOW_EVENT, win_hook, mlx);
	mlx_loop(mlx->init);
}
