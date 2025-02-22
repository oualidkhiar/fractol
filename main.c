/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:03:55 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/22 04:36:24 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h" 

int ft_close_window(t_mlx_data *mlx)
{
    mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
    mlx_destroy_display(mlx->mlx_ptr);
    free(mlx->mlx_ptr);
	if (mlx->c_real)
		free(mlx->c_real);
	if(mlx->c_img)
		free(mlx->c_img);
    exit(0);
}

void parse_mandelbrot(char **av, t_mlx_data *mlx)
{
	if (!ft_strncmp("mandelbrot", av[1], ft_strlen(av[1])) && !(ft_strlen(av[1]) - 10))
    	mlx->flag = -1;
    else
    {
				ft_putstr_fd("Error: Please ensure that the correct argument is provided \
for the Mandelbrot set. Ex run with : ./fractol mandelbrot", 2);
				exit(0);
    }
}

void ft_parsing_argument(char **av, int ac, t_mlx_data *mlx)
{
	if (ac == 2)
		parse_mandelbrot(av, mlx);
    else if (!ft_strncmp("julia", av[1], ft_strlen(av[1])) && !(ft_strlen(av[1]) - 5))
		parse_julia(av, ac, mlx);
    else
        exit(0);
}

int main(int ac, char **av)
{
    t_mlx_data mlx;

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
    return 0;
}
