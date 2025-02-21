/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:54:22 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/21 02:48:43 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double julia_c_real = -0.8;
static double julia_c_img = 0.156;

int ft_check_pixel_in_julia_set(double z_real, double z_img)
{
    double norm;
    int iter = 0;
    double tmp;
    norm = z_real * z_real + z_img * z_img;
    // printf("norm = %f\n", norm );
    while (norm <= 4.0 && iter < MAX_ITER)
    {
        tmp = z_real;
        z_real = z_real * z_real - z_img * z_img + julia_c_real;
        z_img = 2 * tmp * z_img + julia_c_img;
        norm = z_real * z_real + z_img * z_img;
        iter++;
    }
    return (iter);
}

static t_collor *ft_get_color(int iter)
{
    t_collor *ret;

    ret = malloc(sizeof(t_collor));
    ret->red = (iter * 4) % 255;
    ret->green = (iter * 10) % 255;
    ret->blue = (iter * 5) % 255;
    ret->collor = (ret->red << 16) | (ret->green << 8) | ret->blue;
    return (ret);
}

void julia(t_img *img, t_graph graph)
{
    double mapped_x;
    double mapped_y;
    int x;
    int y = 0;
    t_collor *collor;

    while (y < HEIGHT)
    {
        x = 0;
        mapped_y = ((double)y / HEIGHT)* (graph.y_start - graph.y_end) + graph.y_end; 
        while (x < WIDTH)
        {
            mapped_x = ((double)x / WIDTH) * (graph.x_end - graph.x_start) + graph.x_start;
            int iter = ft_check_pixel_in_julia_set(mapped_x, mapped_y);
            if (iter == MAX_ITER)
                ft_put_pixel(img, x, y, 0x000000);
            else
            {
                collor = ft_get_color(iter);
                ft_put_pixel(img, x, y, collor->collor);
                free(collor);
            }
            x++;
        }
        y++;
    }
}