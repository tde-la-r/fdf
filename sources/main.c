/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:39:18 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/02/05 17:34:11 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_mlx(t_mlx *mlx)
{
	mlx->win = NULL;
	mlx->model = NULL;
	mlx->menu = NULL;
	mlx->init = mlx_init();
	if (!mlx->init)
		ft_error_exit(NULL, mlx, "mlx");
	mlx->win = mlx_new_window(mlx->init, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (!mlx->win)
		ft_error_exit(NULL, mlx, "mlx");
	mlx->model = mlx_new_image(mlx->init, MODEL_WIDTH, WIN_HEIGHT);
	if (!mlx->model)
		ft_error_exit(NULL, mlx, "mlx");
	mlx->menu = mlx_png_file_to_image(mlx->init, MENU, NULL, NULL);
	if (!mlx->menu)
		ft_error_exit(NULL, mlx, "mlx");
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->model, MENU_WID, 0);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->menu, 0, 0);
	mlx->proj = 'i';
	calculate_model(mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
	{
		ft_putendl_fd("Error, argument count must be one", 2);
		return (EXIT_FAILURE);
	}
	mlx.map = parse_map(argv[1]);
	start_mlx(&mlx);
	hooks_mlx(&mlx);
	ft_end_mlx(&mlx);
	return (0);
}
