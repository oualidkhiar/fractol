/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 03:43:03 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/23 22:24:44 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_case_space(t_mlx_data *mlx, char *str)
{
	char	*capture;
	int		i;

	i = 0;
	capture = ft_strtrim(str, "	 ");
	while (capture[i] && capture[i] != ' ' && capture[i] != '\t')
		i++;
	mlx->c_real = ft_substr(capture, 0, i);
	while (capture[i] && (capture[i] == ' ' || capture[i] == '\t'))
		i++;
	mlx->c_img = ft_substr(capture, i, INT_MAX);
	free(capture);
	if (!ft_is_valid(mlx->c_img) || !ft_is_valid(mlx->c_real))
		ft_error(2, mlx->c_real, mlx->c_img);
}

int	ft_check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (1);
		i++;
	}
	return (0);
}

void	parse_julia(char **av, int ac, t_mlx_data *mlx)
{
	if (ac == 3)
	{
		if (ft_check_space(av[ac - 1]))
			handle_case_space(mlx, av[ac - 1]);
		else
			ft_error(2, mlx->c_real, mlx->c_img);
	}
	else if (ac == 4)
	{
		mlx->c_real = ft_strtrim(av[2], "	 ");
		mlx->c_img = ft_strtrim(av[3], "	 ");
		if (!ft_is_valid(mlx->c_real) || !ft_is_valid(mlx->c_img))
			ft_error(2, mlx->c_real, mlx->c_img);
	}
	else
		ft_error(4, mlx->c_real, mlx->c_img);
	mlx->flag = 2;
}
