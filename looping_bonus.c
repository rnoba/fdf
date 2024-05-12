/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looping_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:01:59 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/12 17:05:34 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

static t_polygon	ft_rotate_polygon(t_polygon p, t_vec3 r, t_vec2 c)
{
	t_polygon	p0;
	t_polygon	p_rotated;

	p0 = ft_poly_translate(p, ft_vec3(-c.x, -c.y, 0));
	p_rotated = ft_rotate_p_z(ft_rotate_p_y(ft_rotate_p_x(p0, r.x), r.y), r.z);
	return (ft_project(ft_poly_translate(p_rotated, ft_vec3(c.x, c.y, 0))));
}

static	t_polygon	ft_scale_polygon(t_polygon poly, t_map *map)
{
	t_polygon	p;

	p = ft_poly_scale(ft_poly_scale(poly,
				ft_vec3(map->state.scale, map->state.scale,
					map->state.scale)),
			ft_vec3(1, 1, map->state.scale_z));
	return (p);
}

static	t_polygon	ft_p(int idx, t_map *map)
{
	t_polygon	p;

	p = (t_polygon){
		.p1 = map->vert_pool[map->faces[idx].p1],
		.p2 = map->vert_pool[map->faces[idx].p2],
		.p3 = map->vert_pool[map->faces[idx].p3]
	};
	return (p);
}

void	ft_looping(t_map *map)
{
	int			idx;
	t_vec2		c;
	t_vec2		m;
	t_polygon	p_scaled;
	t_polygon	p_rot;

	idx = 0;
	ft_mlx_clear(map->meta.width, map->meta.height, map->meta,
		ft_color_new(0x0, 0x0, 0x0));
	while (idx < map->width * map->height)
	{
		p_scaled = ft_scale_polygon(ft_p(idx++, map), map);
		m = ft_v2(map->state.scale * map->width * 0.5f,
				map->state.scale * map->height * 0.5f);
		c = ft_v2(map->state.translate_x + map->meta.width * 0.5f,
				map->state.translate_y + map->meta.height * 0.5f);
		p_rot = ft_rotate_polygon(
				ft_poly_translate(p_scaled, ft_vec3(c.x - m.x, c.y - m.y, 0)),
				ft_vec3(map->state.rotate_x, map->state.rotate_y,
					map->state.rotate_z), ft_v2(c.x, c.y));
		ft_outline_polygon(p_rot, map->meta);
	}
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.window,
		map->mlx.image, 0, 0);
}
