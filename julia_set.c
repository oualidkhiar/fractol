/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:54:22 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/24 00:10:42 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_check_pixel_in_julia_set(double z_real, double z_img, \
							double julia_c_real, double julia_c_img)
{
	double	norm;
	int		iter;
	double	tmp;

	norm = z_real * z_real + z_img * z_img;
	iter = 0;
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

void	julia(t_img *img, t_graph graph, double \
julia_c_real, double julia_c_img)
{
	double		mapped_x;
	double		mapped_y;
	int			iter_capture;
	t_stored	stored;

	stored.y = 0;
	while (stored.y < HEIGHT)
	{
		stored.x = 0;
		mapped_y = ((double)stored.y / HEIGHT) * \
		(graph.y_start - graph.y_end) + graph.y_end;
		while (stored.x < WIDTH)
		{
			mapped_x = ((double)stored.x / WIDTH) * \
			(graph.x_end - graph.x_start) + graph.x_start;
			iter_capture = ft_check_pixel_in_julia_set(mapped_x, mapped_y, \
									julia_c_real, julia_c_img);
			ft_draw(stored, img, graph, iter_capture);
			stored.x++;
		}
		stored.y++;
	}
}
