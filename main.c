/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:03:55 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/24 01:07:40 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h" 

void	ft_error(int flag, char *address_r, char *address_i)
{
	if (flag == 2)
		ft_putstr_fd("Error: Invalid argument. Please try again \
with valid coordinates. For example: 0.35 0.35", 2);
	else if (flag == 1)
		ft_putstr_fd("Error: Please ensure that the correct argument is provided \
for the Mandelbrot set. Ex run with : ./fractol mandelbrot", 2);
	else if (flag == 4)
		ft_putstr_fd("Wrong arguments provided !\n \
Usage : ./fractol TITLE\n", 2);
	if (address_r)
		free(address_r);
	if (address_i)
		free(address_i);
	exit(0);
}

static int	ft_close_window(t_mlx_data *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	if (mlx->c_real)
		free(mlx->c_real);
	if (mlx->c_img)
		free(mlx->c_img);
	exit(0);
}

static void	parse_mandelbrot(char **av, t_mlx_data *mlx)
{
	if ((!ft_strncmp("mandelbrot", av[1], 10)) && (ft_strlen(av[1]) == 10))
		mlx->flag = -1;
	else if ((!ft_strncmp("bonus", av[1], 5)) && (ft_strlen(av[1]) == 5))
		mlx->flag = 3;
	else
		ft_error(1, NULL, NULL);
}

static void	ft_parsing_argument(char **av, int ac, t_mlx_data *mlx)
{
	if (ac == 2)
		parse_mandelbrot(av, mlx);
	else if (!ft_strncmp("julia", av[1], ft_strlen(av[1])) \
								&& !(ft_strlen(av[1]) - 5))
		parse_julia(av, ac, mlx);
	else
		ft_error(4, NULL, NULL);
}

int	main(int ac, char **av)
{
	t_mlx_data	mlx;

	mlx.zoom = 0.5;
	mlx.graph.x_start = -2;
	mlx.graph.x_end = 2;
	mlx.graph.y_start = -2;
	mlx.graph.y_end = 2;
	mlx.graph.quantity_blue = 0;
	mlx.graph.quantity_red = 0;
	mlx.graph.quantity_green = 0;
	mlx.c_img = NULL;
	mlx.c_real = NULL;
	ft_parsing_argument(av, ac, &mlx);
	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Fractal Window");
	mlx_key_hook(mlx.mlx_win, check_key, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, ft_close_window, &mlx);
	mlx_mouse_hook(mlx.mlx_win, mapped_and_zoom, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, render_next_frame, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
