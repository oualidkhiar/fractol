/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_in_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:05:19 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/23 22:40:19 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_out(double mouse_x, double mouse_y, t_mlx_data *mlx)
{
	mlx->graph.x_start = mouse_x - (mouse_x - mlx->graph.x_start) / mlx->zoom;
	mlx->graph.x_end = (mlx->graph.x_end - mouse_x) / mlx->zoom + mouse_x;
	mlx->graph.y_start = mouse_y - (mouse_y - mlx->graph.y_start) / mlx->zoom;
	mlx->graph.y_end = (mlx->graph.y_end - mouse_y) / mlx->zoom + mouse_y;
}

static void	zoom_in(double mouse_x, double mouse_y, t_mlx_data *mlx)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = mlx->graph.x_start;
	tmp_y = mlx->graph.y_start;
	mlx->graph.x_start = mouse_x - ((mouse_x - mlx->graph.x_start) * mlx->zoom);
	mlx->graph.x_end = ((mlx->graph.x_end - tmp_x) * mlx->zoom) + \
												mlx->graph.x_start;
	mlx->graph.y_start = mouse_y - ((mouse_y - mlx->graph.y_start) * mlx->zoom);
	mlx->graph.y_end = ((mlx->graph.y_end - tmp_y) * mlx->zoom) + \
												mlx->graph.y_start;
}

static void	mouse_event(int key_code, double x, double y, t_mlx_data *mlx)
{
	if (key_code == 5)
		zoom_in(x, y, mlx);
	else if (key_code == 4)
		zoom_out(x, y, mlx);
}

int	mapped_and_zoom(int key_code, int x, int y, t_mlx_data *mlx)
{
	double	mapped_x_mouse;
	double	mapped_y_mouse;

	mapped_x_mouse = ((double)x / WIDTH) * (mlx->graph.x_end - \
					mlx->graph.x_start) + mlx->graph.x_start;
	mapped_y_mouse = (((double)y * (-1)) / HEIGHT) * (mlx->graph.y_end - \
								mlx->graph.y_start) + mlx->graph.y_end;
	mouse_event(key_code, mapped_x_mouse, mapped_y_mouse, mlx);
	return (0);
}
