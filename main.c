/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:03:55 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/21 12:30:37 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h" 

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
    if (ac == 1)
        exit(0);
    if (!ft_strncmp("mandelbrot", av[1], 10) && !(ft_strlen(av[1]) - 10))
        mlx.flag = 1;
    else if (!ft_strncmp("julia", av[1], 5) && !(ft_strlen(av[1]) - 5))
        mlx.flag = 2;
    mlx.mlx_ptr = mlx_init();
    mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Fractal Window");
    mlx_key_hook(mlx.mlx_win, check_key, &mlx);
    mlx_mouse_hook(mlx.mlx_win, mapped_and_zoom, &mlx);
    mlx_loop_hook(mlx.mlx_ptr, render_next_frame, &mlx);
    mlx_loop(mlx.mlx_ptr);
    return 0;
}
