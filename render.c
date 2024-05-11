/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:06:14 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/10 17:59:00 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	ft_pixel_put(t_ivec2 p, t_meta m, t_color color)
{
	char	*mem;

	mem = m.buffer + p.y * m.sl + p.x * (m.bpp / 8);
	*mem++ = color.b;
	*mem++ = color.g;
	*mem = color.r;
}

int	ft_check_y(int *error, t_ivec2 *p0, t_ivec2 *p1, t_ivec2 c)
{
	if (2 * (*error) >= c.y)
	{
		if (p0->x == p1->x)
			return (0);
		*error = (*error) + c.y;
		p0->x = p0->x + c.x;
	}
	return (1);
}

void	bresenham(t_ivec2 p0, t_ivec2 p1, t_meta meta, t_dcolor c)
{
	t_vec3	start;
	t_vec3	end;
	t_ivec2	d;
	t_ivec2	s;
	int		error;

	ft_init_bres(&p0, &p1, &s, &d);
	error = d.x + d.y;
	start = ft_vec3(p0.x, p0.y, 0);
	end = ft_vec3(p1.x, p1.y, 0);
	while (1)
	{
		ft_paint(c, p0, meta, ft_pytagorean_dist(start, end, p0));
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		if (!ft_check_y(&error, &p0, &p1, ft_ivec2(s.x, d.y)))
			break ;
		if (2 * error <= d.x)
		{
			if (p0.y == p1.y)
				break ;
			error = error + d.x;
			p0.y = p0.y + s.y;
		}
	}
}

void	ft_outline_polygon(t_polygon poly, t_meta meta)
{
	t_ivec2	p0;
	t_ivec2	p1;
	t_ivec2	p2;

	p0 = ft_ivec2(poly.p1.x, poly.p1.y);
	p1 = ft_ivec2(poly.p2.x, poly.p2.y);
	p2 = ft_ivec2(poly.p3.x, poly.p3.y);
	bresenham(p0, p1, meta, ft_colord(poly.p2.color, poly.p1.color));
	bresenham(p0, p2, meta, ft_colord(poly.p3.color, poly.p1.color));
}

void	ft_mlx_clear(int width, int height, t_meta meta, t_color c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			ft_pixel_put(ft_ivec2(i, j++), meta, c);
		}
		i++;
	}
}
