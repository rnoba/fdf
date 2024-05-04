/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:06:14 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/01 16:31:02 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	ft_pixel_put(int x, int y, t_meta m, t_color color)
{
	char	*mem;

	mem = m.buffer + y * m.sl + x * (m.bpp / 8);
	*mem++ = color.b;
	*mem++ = color.g;
	*mem = color.r;
}


//TODO(study this)
//TODO(refactor)
void	bresenham(int x0, int y0, int x1, int y1, t_meta meta, t_color cs, t_color ce)
{
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int error = dx + dy;

	t_vec3	start;
	t_vec3	end;

	start = ft_vec3(x0, y0, 0);
	end = ft_vec3(x1, y1, 0);
    while (1)
	{
		if (x0 < meta.width && y0 < meta.height && x0 > 0 && y0 > 0)
		{
			t_color	color = ft_lerpcolor(cs, ce, ft_pytagorean_dist(start, end, ft_vec3(x0, y0, 0)));
			ft_pixel_put(x0, y0, meta, color);
		}
        if (x0 == x1 && y0 == y1)
		{
			break;
		}
        int e2 = 2 * error;
        if (e2 >= dy)
		{
            if (x0 == x1)
			{
				break;
			}
            error = error + dy;
            x0 = x0 + sx;
		}
        if (e2 <= dx)
		{
            if (y0 == y1)
			{
				break;
			}
            error = error + dx;
            y0 = y0 + sy;
		}
	}
}

void	ft_outline_polygon(t_polygon poly, t_meta meta)
{
	bresenham(poly.p1.x, poly.p1.y, poly.p2.x, poly.p2.y, meta, poly.p2.color, poly.p1.color);
	bresenham(poly.p1.x, poly.p1.y, poly.p3.x, poly.p3.y, meta, poly.p3.color, poly.p1.color);
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
			ft_pixel_put(i, j++, meta, c);
		}
		i++;
	}
}
