/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:25:11 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/23 21:52:50 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_is_valid(char *str)
{
	int	i;
	int	seen;

	seen = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (seen)
				return (0);
			seen = 1;
		}
		else if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_sign_and_init(const char **str, double *res, \
										double *result, double *div)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	*res = 0.0;
	*div = 10.0;
	*result = 0.0;
	return (sign);
}

double	ft_atoi(const char *str)
{
	double	res;
	double	div;
	double	result;
	int		sign;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = ft_check_sign_and_init(&str, &res, &result, &div);
	while (*str && *str >= 48 && *str <= 57)
	{
		res = res * (double)10 + (double)*str - (double)48;
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str && *str >= 48 && *str <= 57)
		{
			result = result + (*str - 48) / div;
			div *= 10;
			str++;
		}
	}
	return ((result + res) * sign);
}
