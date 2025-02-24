/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 00:41:48 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/24 14:19:26 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_pixel_in_mandelbrot_set(double cx_real, double cy_img)
{
	double	z_real;
	double	z_img;
	double	norm;
	double	tmp;
	int		iter;

	z_real = 0;
	z_img = 0;
	norm = cx_real * cx_real + cy_img * cy_img;
	iter = 0;
	while (norm <= 4.0 && iter < MAX_ITER)
	{
		tmp = z_real;
		z_real = z_real * ((z_real * z_real) - 3 * (z_img * z_img)) + cx_real;
		z_img = z_img * (3 * (tmp * tmp) - (z_img * z_img)) + cy_img;
		norm = z_real * z_real + z_img * z_img;
		iter++;
	}
	return (iter);
}

void	bonus_fract(t_img *img, t_graph graph)
{
	t_stored	stor;
	double		mapped_y;
	int			iter_capture;
	double		mapped_x;

	stor.y = 0;
	while (stor.y < HEIGHT)
	{
		stor.x = 0;
		mapped_y = ((double)stor.y / HEIGHT) * (graph.y_start - graph.y_end) + \
																graph.y_end;
		while (stor.x < WIDTH)
		{
			mapped_x = ((double)stor.x / WIDTH) * \
			(graph.x_end - graph.x_start) + graph.x_start;
			iter_capture = check_pixel_in_mandelbrot_set(mapped_x, \
																	mapped_y);
			ft_draw(stor, img, graph, iter_capture);
			stor.x++;
		}
		stor.y++;
	}
}
