/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:55:43 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/21 13:08:54 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

# define HEIGHT 1000
# define WIDTH 1000
# define MAX_ITER 100
# define MAX_COLOR 255
# define MIN_COLOR 0

typedef struct s_collor
{   
    unsigned int collor;
    int          red;
    int          blue;
    int          green;
}   t_collor;

typedef struct s_graph {
    double x_start;
    double x_end;
    double y_start;
    double y_end;
    double offset;
    int    quantity_blue;
    int     quantity_red;
    int     quantity_green;
} t_graph;

typedef struct s_img {
    void    *img;
    char    *addr;
    int     line_length;
    int     bpp;
    int     endian;
} t_img;

typedef struct s_mlx_data
{
    void *mlx_ptr;
    void *mlx_win;
    int *data;
    int flag;
    double  zoom;
    t_img *new_img;
    t_graph graph;
}   t_mlx_data;

int		check_key(int key_pressed, t_mlx_data *mlx);
int		mapped_and_zoom(int key_code, int x, int y, t_mlx_data *mlx);
int		render_next_frame(t_mlx_data *mlx);
t_img	*new_image(t_mlx_data *mlx);
void	ft_destroy_img(t_mlx_data *mlx);
void	ft_put_pixel(t_img *data, int x, int y, int color);
void	mandelbrot(t_img *img, t_graph graph);
void	julia(t_img *img, t_graph graph);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void julia(t_img *img, t_graph graph);
# endif
