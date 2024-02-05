/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:39:09 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/02/04 23:39:00 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_r(int argb)
{
	argb >>= 16;
	argb &= 0xff;
	return (argb);
}

int	get_g(int argb)
{
	argb >>= 8;
	argb &= 0xff;
	return (argb);
}

int	get_b(int argb)
{
	argb &= 0xff;
	return (argb);
}

int	get_line_radient(t_pt p1, t_pt p2, int start, double slope)
{
	double	length;
	double	pixel_pos;
	double	ratio;
	int		color;

	if (slope <= 1 && slope >= -1)
	{
		length = p2.x_proj - start;
		pixel_pos = p1.x_proj - start;
	}
	else
	{
		length = p2.y_proj - start;
		pixel_pos = p1.y_proj - start;
	}
	if (!length)
		ratio = 0;
	else
		ratio = pixel_pos / length;
	color = get_radient(ratio, p1.color, p2.color);
	return (color);
}

int	get_radient(double ratio, int color1, int color2)
{
	int		red;
	int		green;
	int		blue;

	red = get_r(color1) * (1 - ratio) + get_r(color2) * ratio;
	green = get_g(color1) * (1 - ratio) + get_g(color2) * ratio;
	blue = get_b(color1) * (1 - ratio) + get_b(color2) * ratio;
	return (0xff << 24 | red << 16 | green << 8 | blue);
}
