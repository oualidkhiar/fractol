/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:51:02 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/23 22:30:18 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	scroll_left_right(int key_pressed, t_graph *graph)
{
	graph->offset = (graph->y_end - graph->y_start) * 0.25;
	if (key_pressed == 65362)
	{
		graph->y_end -= graph->offset;
		graph->y_start -= graph->offset;
	}
	else if (key_pressed == 65364)
	{
		graph->y_start += graph->offset;
		graph->y_end += graph->offset;
	}
}

static void	scroll_down_up(int key_pressed, t_graph *graph)
{
	graph->offset = (graph->x_end - graph->x_start) * 0.25;
	if (key_pressed == 65361)
	{
		graph->x_start += graph->offset;
		graph->x_end += graph->offset;
	}
	else if (key_pressed == 65363)
	{
		graph->x_start -= graph->offset;
		graph->x_end -= graph->offset;
	}
}

static void	increment_color_target(int key, t_graph *target)
{
	if (key == 98)
	{
		target->quantity_blue += 2;
		if (target->quantity_blue > MAX_COLOR)
			target->quantity_blue = 0;
	}
	else if (key == 114)
	{
		target->quantity_red += 2;
		if (target->quantity_red > MAX_COLOR)
			target->quantity_red = 0;
	}
	else if (key == 103)
	{
		target->quantity_green += 2;
		if (target->quantity_green > MAX_COLOR)
			target->quantity_green = 0;
	}
}

static void	dicrement_color_target(int key, t_graph *target)
{
	if (key == 65435)
	{
		target->quantity_blue -= 2;
		if (target->quantity_blue < MIN_COLOR)
			target->quantity_blue = 0;
	}
	else if (key == 65436)
	{
		target->quantity_red -= 2;
		if (target->quantity_red < MIN_COLOR)
			target->quantity_red = 0;
	}
	else if (key == 65433)
	{
		target->quantity_green -= 2;
		if (target->quantity_green < MIN_COLOR)
			target->quantity_green = 0;
	}
}

int	check_key(int key_pressed, t_mlx_data *mlx)
{
	if (key_pressed == 98 || key_pressed == 114 || key_pressed == 103)
		increment_color_target(key_pressed, &mlx->graph);
	else if (key_pressed == 65436 || key_pressed == 65433 || \
										key_pressed == 65435)
		dicrement_color_target(key_pressed, &mlx->graph);
	else if (key_pressed == 65307)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		if (mlx->c_img)
			free(mlx->c_img);
		if (mlx->c_real)
			free(mlx->c_real);
		exit(0);
	}
	else if (key_pressed == 65362 || key_pressed == 65364)
		scroll_left_right(key_pressed, &mlx->graph);
	else if (key_pressed == 65361 || key_pressed == 65363)
		scroll_down_up(key_pressed, &mlx->graph);
	return (0);
}
