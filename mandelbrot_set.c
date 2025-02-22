/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:08:37 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/21 21:41:42 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int check_pixel_in_mandelbrot_set(double cx_real, double cy_img)
{
    double z_real, z_img, norm;
    double tmp;

    z_real = 0;
    z_img = 0;
    norm = cx_real*cx_real + cy_img*cy_img;
    int iter = 0;
    while (norm <= 4.0 && iter < MAX_ITER)
    {
        tmp = z_real;
        z_real = z_real * z_real - (z_img * z_img) + cx_real;
        z_img = 2.0 * tmp * z_img + cy_img;
        norm = z_real * z_real + z_img * z_img;
        iter++;
    }
    return (iter);
}

static t_collor *get_color(int iter, int quantity_blue, int quantity_red, int quantity_green)
{
    t_collor *ret;

    ret = malloc(sizeof(t_collor));
    ret->red = (iter * (10 + quantity_red)) % 255;
    ret->green = (iter * (2 + quantity_green)) % 255;
    ret->blue = (iter * (5 + quantity_blue)) % 255;
    ret->collor = (ret->red << 16) | (ret->green << 8) | ret->blue;
    return (ret);
}

void mandelbrot(t_img *img, t_graph graph)
{
    double y;
    int iter_capture;
    int x;
    double mapped_y;
    t_collor *collor;
    double mapped_x;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        mapped_y = ((double)y / HEIGHT)* (graph.y_start - graph.y_end) + graph.y_end;
        while (x < WIDTH)
        {
            mapped_x = ((double)x / WIDTH) * (graph.x_end - graph.x_start) + graph.x_start;
            iter_capture = check_pixel_in_mandelbrot_set(mapped_x, mapped_y);
            if (iter_capture == MAX_ITER)
                ft_put_pixel(img, x, y, 0x000000);
            else
            {
                collor = get_color(iter_capture, graph.quantity_blue, graph.quantity_red, graph.quantity_green);
                ft_put_pixel(img, x, y, collor->collor);
                free(collor);
            }
            x++;
        }
        y++;
    }
}
