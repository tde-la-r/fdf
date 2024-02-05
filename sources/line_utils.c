/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:21:05 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/02/05 17:35:23 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_put_pixel(int x, int y, int color, t_mlx mlx)
{
	if (x < MODEL_WIDTH && y < WIN_HEIGHT)
		mlx_set_image_pixel(mlx.init, mlx.model, x, y, color);
}
