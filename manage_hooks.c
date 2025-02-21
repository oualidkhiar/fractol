/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:51:02 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/21 01:42:51 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void scroll_left_right(int key_pressed, t_graph *graph)
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

static void scroll_down_up(int key_pressed, t_graph *graph)
{
   graph->offset = (graph->x_end -graph->x_start) * 0.25;
    if (key_pressed == 65361)
    {
       graph->x_start +=graph->offset;
       graph->x_end +=graph->offset;
    }
    else if (key_pressed == 65363)
    {
       graph->x_start -=graph->offset;
       graph->x_end -=graph->offset;
    }
}

int check_key(int key_pressed, t_mlx_data *mlx)
{
    if (key_pressed == 65307)
    {
        mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
        mlx_destroy_display(mlx->mlx_ptr);
        free(mlx->mlx_ptr);
        exit(0);
    }
    else if (key_pressed == 65362 || key_pressed == 65364)
        scroll_left_right(key_pressed, &mlx->graph);
    else if (key_pressed == 65361 || key_pressed == 65363)
        scroll_down_up(key_pressed, &mlx->graph);
    return 0;
}
