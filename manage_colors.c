/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 00:08:33 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/24 00:09:25 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_collor	*get_color(int iter, int quantity_blue, int quantity_red, \
													int quantity_green)
{
	t_collor	*ret;

	ret = malloc(sizeof(t_collor));
	if (!ret)
		return (NULL);
	ret->red = (unsigned char)(iter * (10 + quantity_red)) % 255;
	ret->green = (unsigned char)(iter * (2 + quantity_green)) % 255;
	ret->blue = (unsigned char)(iter * (5 + quantity_blue)) % 255;
	ret->collor = (ret->red << 16) | (ret->green << 8) | ret->blue;
	return (ret);
}

void	ft_draw(t_stored stor, t_img *img, t_graph graph, int iter_capture)
{
	t_collor	*collor;

	if (iter_capture == MAX_ITER)
		ft_put_pixel(img, stor.x, stor.y, 0x000000);
	else
	{
		collor = get_color(iter_capture, graph.quantity_blue, \
		graph.quantity_red, graph.quantity_green);
		ft_put_pixel(img, stor.x, stor.y, collor->collor);
		free(collor);
	}
}
