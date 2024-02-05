/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:22:04 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/02/05 17:16:37 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(t_parser *data)
{
	data->map->x_scale = (MODEL_WIDTH / 2) / data->map->col_nb;
	if (data->map->x_scale < 1)
		data->map->x_scale = 1;
	data->map->y_scale = (WIN_HEIGHT / 2) / data->map->line_nb;
	if (data->map->y_scale < 1)
		data->map->y_scale = 1;
	data->map->z_scale = (data->map->x_scale + data->map->y_scale) / 2;
	data->map->x_rot = 0;
	data->map->y_rot = 0;
	data->map->z_rot = 0;
	data->map->x_translate = 0;
	data->map->y_translate = 0;
	data->map->z_min = INT_MAX;
	data->map->z_max = INT_MIN;
}

void	check_columns_number(int to_check, t_parser *data)
{
	static int	nb_col = 0;

	if (!to_check)
		ft_error_exit(data, NULL, "empty line");
	if (!nb_col)
		nb_col = to_check;
	if (to_check != nb_col)
		ft_error_exit(data, NULL, "nb_col");
}

int	count_columns(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s == '\n')
			return (count);
		if (*s)
			count++;
		while (*s != ' ' && *s)
			s++;
	}
	return (count);
}

void	count_size(char *file, t_parser *data)
{
	char	*line;

	data->fd = open(file, O_RDONLY);
	if (data->fd == -1)
		ft_error_exit(data, NULL, "open");
	data->map->line_nb = 0;
	data->map->col_nb = 0;
	line = get_next_line(data->fd);
	while (line)
	{
		data->map->col_nb = count_columns(line);
		free(line);
		check_columns_number(data->map->col_nb, data);
		data->map->line_nb++;
		line = get_next_line(data->fd);
	}
	close(data->fd);
	data->fd = -1;
	if (!data->map->col_nb || !data->map->line_nb)
		ft_error_exit(data, NULL, "empty");
}

void	malloc_map(char *file, t_parser *data)
{
	int	i;

	data->array = NULL;
	data->fd = -1;
	data->map = malloc(sizeof(t_map));
	data->map->pt = NULL;
	if (!data->map)
		ft_error_exit(data, NULL, "malloc");
	count_size(file, data);
	init_map(data);
	data->map->pt = malloc(sizeof(t_pt *) * (data->map->line_nb));
	if (!data->map->pt)
		ft_error_exit(data, NULL, "malloc");
	i = 0;
	while (i < data->map->line_nb)
	{
		data->map->pt[i] = malloc(sizeof(t_pt) * data->map->col_nb);
		if (!data->map->pt[i])
			ft_error_exit(data, NULL, "malloc");
		i++;
	}
}
