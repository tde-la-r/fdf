/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:26:04 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/02/05 20:56:56 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_HEIGHT 963
# define WIN_WIDTH 1920
# define MENU_WID 240
# define MODEL_WIDTH 1680
# define MENU "Menu.png"
# define COLOR_NAVY 0x000080
# define COLOR_TEAL 0x008080
# define COLOR_GRASS 0x008000
# define COLOR_MAROON 0x800000
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include <SDL2/SDL_scancode.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_pt
{
	int		x;
	int		y;
	int		z;
	int		file_color;
	int		color;
	int		x_proj;
	int		y_proj;
}			t_pt;

typedef struct s_map
{
	int		col_nb;
	int		line_nb;
	double	x_scale;
	double	y_scale;
	double	z_scale;
	double	x_rot;
	double	y_rot;
	double	z_rot;
	int		x_translate;
	int		y_translate;
	int		z_min;
	int		z_max;
	t_pt	**pt;
}			t_map;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*model;
	void	*menu;
	int		x_mouse;
	int		y_mouse;
	char	proj;
	t_map	*map;
}			t_mlx;

typedef struct s_parser
{
	int		fd;
	char	**array;
	t_map	*map;
}			t_parser;

t_map	*parse_map(char *file);
void	malloc_map(char *file, t_parser *data);
void	draw_map(t_mlx *mlx);

void	calculate_model(t_mlx *mlx);
void	apply_scale(int *x, int *y, int *z, t_map *map);
void	apply_rotation(int *x, int *y, int *z, t_map *map);
void	apply_isometric(int *x, int *y, int z);
void	apply_translation(int *x, int *y, t_map *map);

void	draw_line(t_pt p1, t_pt p2, t_mlx mlx);
void	ft_swap(int *a, int *b);
void	ft_put_pixel(int x, int y, int color, t_mlx mlx);
int		get_line_radient(t_pt p1, t_pt p2, int start, double slope);
int		get_radient(double ratio, int color1, int color2);

void	hooks_mlx(t_mlx *mlx);
void	scale_z(int key, t_mlx *mlx);
void	zoom_key(int key, t_mlx *mlx);
int		zoom_mouse(int event, void *param);
void	rotate(int key, t_mlx *mlx);
void	change_projection(int key, t_mlx *mlx);
void	translate_key(int key, t_mlx *mlx);
void	change_colors(t_mlx *mlx);
void	reset_colors(t_mlx *mlx);

void	ft_error_exit(t_parser *to_free, t_mlx *mlx, char *err);
void	ft_free_array(char **array);
void	ft_free_map(t_map *map);
void	ft_end_mlx(t_mlx *mlx);

#endif
