/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:12:07 by oukhiar           #+#    #+#             */
/*   Updated: 2025/02/23 21:53:33 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*base_s2;
	size_t	s_len;
	char	*s2;

	s_len = ft_strlen(s1);
	s2 = (char *)malloc(s_len * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	base_s2 = s2;
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (base_s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	char	*base_sub;

	if (!s)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	sub_str = (char *)malloc(sizeof(char) * len + 1);
	if (sub_str == NULL)
		return (NULL);
	base_sub = sub_str;
	s += start;
	while (len > 0)
	{
		*sub_str++ = *s++;
		len--;
	}
	*sub_str = '\0';
	return (base_sub);
}

static size_t	countlen(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j] && s1[i])
	{
		if (set[j] == s1[i])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	last_s1;
	char	*ret;

	if (!s1 || !set)
		return (0);
	j = 0;
	i = countlen(s1, set);
	last_s1 = ft_strlen(s1) - 1;
	if (i > last_s1)
		return (ft_substr(s1, 0, 0));
	while (set[j] && s1[last_s1])
	{
		if (set[j] == s1[last_s1])
		{
			last_s1--;
			j = 0;
		}
		else
			j++;
	}
	ret = ft_substr(s1, i, last_s1 - i + 1);
	return (ret);
}
