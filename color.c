/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:07:10 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/07 17:58:06 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

static int	ft_get_place_value(const char *base, char c)
{
	int	place;

	place = 0;
	while (base[place] != c)
	{
		place++;
	}
	return (place);
}

t_color	ft_hex_to_color(int n)
{
	t_color	color;

	color = (t_color){
		.r = n >> 16 & 0xFF,
		.g = n >> 8 & 0xFF,
		.b = n & 0xFF
	};
	return (color);
}

t_color	ft_parse_color(char *c, int len)
{
	int			idx;
	int			n;

	if (len > 0)
		len -= 1;
	if (!ft_strncmp("0x", c, 2))
	{
		c = ft_strchr(c, 'x') + 1;
		len -= 2;
	}
	n = 0;
	idx = 0;
	while (idx < len)
	{
		n = n * 16;
		n += ft_get_place_value("0123456789abcdef", ft_tolower(c[idx++]));
	}
	return (ft_hex_to_color(n));
}

float	ft_lerp(float a, float b, float t)
{
	return ((1.0f - t) * a + b * t);
}

t_color	ft_lerpcolor(t_color start, t_color end, float t)
{
	t_color	res;

	res = (t_color){
		.r = ft_lerp(start.r, end.r, t),
		.g = ft_lerp(start.g, end.g, t),
		.b = ft_lerp(start.b, end.b, t)
	};
	return (res);
}
