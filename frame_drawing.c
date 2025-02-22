/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:00:56 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/22 05:08:21 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_put_pixel(t_img *data, int x, int y, int color)
{
    if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT) {
        printf("ERROR: put pixel");
        return ;
    }
    char *target = data->addr + (y * data->line_length) + (x * (data->bpp / 8));
    *((int *)target) = color;
}

void ft_destroy_img(t_mlx_data *mlx)
{
    mlx_destroy_image(mlx->mlx_ptr, mlx->new_img->img);
    free(mlx->new_img);
}

t_img *new_image(t_mlx_data *mlx)
{
    mlx->new_img = malloc(sizeof(t_img));
    mlx->new_img->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
    mlx->new_img->addr = mlx_get_data_addr(mlx->new_img->img, &mlx->new_img->bpp, &mlx->new_img->line_length, &mlx->new_img->endian);
    return mlx->new_img;
}

int render_next_frame(t_mlx_data *mlx)
{
    mlx->new_img = new_image(mlx);
    if (mlx->flag == -1)
        mandelbrot(mlx->new_img, mlx->graph);
    if (mlx->flag == 2)
    {
        double c_real = ft_atoi(mlx->c_real);
        double c_img = ft_atoi(mlx->c_img);
        julia(mlx->new_img, mlx->graph, c_real, c_img);
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->new_img->img, 0, 0);
    ft_destroy_img(mlx);
    return 0;
}
