/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:02:50 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/02/05 17:18:09 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_rotation(int *a, int *b, double rotation)
{
	int	tmp;

	tmp = *a;
	*a = *a * cos(rotation) - *b * sin(rotation);
	*b = tmp * sin(rotation) + *b * cos(rotation);
}

void	apply_rotation(int *x, int *y, int *z, t_map *map)
{
	calculate_rotation(x, y, map->z_rot);
	calculate_rotation(z, y, map->x_rot);
	calculate_rotation(z, x, map->y_rot);
}

void	apply_scale(int *x, int *y, int *z, t_map *map)
{
	*x *= map->x_scale;
	*y *= map->y_scale;
	*z *= map->z_scale;
}

void	apply_isometric(int *x, int *y, int z)
{
	int	tmp_x;

	tmp_x = *x;
	*x = tmp_x - *y;
	*y = (tmp_x + *y) * 0.5 - z;
}

void	apply_translation(int *x, int *y, t_map *map)
{
	*x += MODEL_WIDTH / 2 + map->x_translate;
	*y += WIN_HEIGHT / 2 + map->y_translate;
}
