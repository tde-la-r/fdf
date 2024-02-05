/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:29:04 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/02/04 23:09:40 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_case_1(t_pt p1, t_pt p2, double slope, t_mlx mlx)
{
	double	y_from;
	double	y_next;
	double	y_line;
	int		color;
	int		start;

	ft_put_pixel(p1.x_proj, p1.y_proj, p1.color, mlx);
	y_line = p1.y_proj;
	y_from = p1.y_proj;
	start = p1.x_proj;
	p1.x_proj++;
	while (p1.x_proj <= p2.x_proj)
	{
		color = get_line_radient(p1, p2, start, slope);
		y_line += slope;
		y_next = y_from + 1;
		if (y_line - y_from <= y_next - y_line)
			ft_put_pixel(p1.x_proj, y_from, color, mlx);
		else
		{
			ft_put_pixel(p1.x_proj, y_next, color, mlx);
			y_from = y_next;
		}
		p1.x_proj++;
	}
}

void	draw_line_case_2(t_pt p1, t_pt p2, double slope, t_mlx mlx)
{
	double	x_from;
	double	x_next;
	double	x_line;
	int		color;
	int		start;

	ft_put_pixel(p1.x_proj, p1.y_proj, p1.color, mlx);
	x_line = p1.x_proj;
	x_from = p1.x_proj;
	start = p1.y_proj;
	p1.y_proj++;
	while (p1.y_proj <= p2.y_proj)
	{
		color = get_line_radient(p1, p2, start, slope);
		x_line += 1 / slope;
		x_next = x_from + 1;
		if (x_line - x_from <= x_next - x_line)
			ft_put_pixel(x_from, p1.y_proj, color, mlx);
		else
		{
			ft_put_pixel(x_next, p1.y_proj, color, mlx);
			x_from = x_next;
		}
		p1.y_proj++;
	}
}

void	draw_line_case_3(t_pt p1, t_pt p2, double slope, t_mlx mlx)
{
	double	y_from;
	double	y_next;
	double	y_line;
	int		color;
	int		start;

	ft_put_pixel(p1.x_proj, p1.y_proj, p1.color, mlx);
	y_line = p1.y_proj;
	y_from = p1.y_proj;
	start = p1.x_proj;
	p1.x_proj++;
	while (p1.x_proj <= p2.x_proj)
	{
		color = get_line_radient(p1, p2, start, slope);
		y_line += slope;
		y_next = y_from - 1;
		if (y_from - y_line <= y_line - y_next)
			ft_put_pixel(p1.x_proj, y_from, color, mlx);
		else
		{
			ft_put_pixel(p1.x_proj, y_next, color, mlx);
			y_from = y_next;
		}
		p1.x_proj++;
	}
}

void	draw_line_case_4(t_pt p1, t_pt p2, double slope, t_mlx mlx)
{
	double	x_from;
	double	x_next;
	double	x_line;
	int		color;
	int		start;

	ft_put_pixel(p1.x_proj, p1.y_proj, p1.color, mlx);
	x_line = p1.x_proj;
	x_from = p1.x_proj;
	start = p1.y_proj;
	p1.y_proj--;
	while (p1.y_proj >= p2.y_proj)
	{
		color = get_line_radient(p1, p2, start, slope);
		x_line -= 1 / slope;
		x_next = x_from + 1;
		if (x_line - x_from <= x_next - x_line)
			ft_put_pixel(x_from, p1.y_proj, color, mlx);
		else
		{
			ft_put_pixel(x_next, p1.y_proj, color, mlx);
			x_from = x_next;
		}
		p1.y_proj--;
	}
}

void	draw_line(t_pt p1, t_pt p2, t_mlx mlx)
{
	double	slope;

	if (p1.x_proj > p2.x_proj)
	{
		ft_swap(&p1.x_proj, &p2.x_proj);
		ft_swap(&p1.y_proj, &p2.y_proj);
		ft_swap(&p1.color, &p2.color);
	}
	slope = ((double) p2.y_proj - (double) p1.y_proj) / \
			((double) p2.x_proj - (double) p1.x_proj);
	if (slope > 1)
		draw_line_case_2(p1, p2, slope, mlx);
	else if (slope >= 0)
		draw_line_case_1(p1, p2, slope, mlx);
	else if (slope < -1)
		draw_line_case_4(p1, p2, slope, mlx);
	else
		draw_line_case_3(p1, p2, slope, mlx);
}
