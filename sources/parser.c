/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:52:33 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/02/04 22:09:17 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(char *point, t_parser *data)
{
	int		color;
	int		count;
	char	*comma;

	color = 0xffffffff;
	comma = ft_strchr(point, ',');
	if (comma)
	{
		comma++;
		if (ft_strncmp(comma, "0x", 2) || !ft_isbase(*(comma + 2), 16))
			ft_error_exit(data, NULL, "color");
		comma += 2;
		color = ft_atoi_radix(comma, 16);
		count = 0;
		while (ft_isbase(*comma, 16))
		{
			count++;
			comma++;
		}
		if ((*comma != '\n' && *comma != '\0') || count > 6)
			ft_error_exit(data, NULL, "color");
		color |= 0xff << 24;
	}
	return (color);
}

void	process_line(t_parser *data)
{
	static int	i = 0;
	int			j;
	int			y_calculated;

	y_calculated = i - data->map->line_nb / 2;
	j = 0;
	while (j < data->map->col_nb)
	{
		data->map->pt[i][j].x = j - data->map->col_nb / 2;
		data->map->pt[i][j].y = y_calculated;
		data->map->pt[i][j].z = ft_atoi(data->array[j]);
		if (data->map->pt[i][j].z < data->map->z_min)
			data->map->z_min = data->map->pt[i][j].z;
		if (data->map->pt[i][j].z > data->map->z_max)
			data->map->z_max = data->map->pt[i][j].z;
		data->map->pt[i][j].color = get_color(data->array[j], data);
		data->map->pt[i][j].file_color = data->map->pt[i][j].color;
		j++;
	}
	ft_free_array(data->array);
	i++;
}

t_map	*parse_map(char *file)
{
	char		*line;
	t_parser	data;

	malloc_map(file, &data);
	data.fd = open(file, O_RDONLY);
	if (data.fd == -1)
		ft_error_exit(&data, NULL, "open");
	line = get_next_line(data.fd);
	while (line)
	{
		data.array = ft_split(line, ' ');
		free(line);
		if (!data.array)
			ft_error_exit(&data, NULL, "malloc");
		process_line(&data);
		line = get_next_line(data.fd);
	}
	close(data.fd);
	return (data.map);
}
