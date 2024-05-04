/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:01:59 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/04 17:02:20 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

static t_polygon	ft_rotate_polygon_isometric(t_polygon poly, float rx, float ry, t_vec2 center)
{
	t_polygon p0 = ft_poly_translate(poly, ft_vec3(-center.x, -center.y, 0));
	t_polygon px = ft_rotate_poly_x(p0, rx);
	t_polygon py = ft_rotate_poly_y(px, ry);
	t_polygon p1 = ft_poly_translate(py, ft_vec3(center.x, center.y, 0));
	return (ft_isometric_projection(p1, (10 / 180) * M_PI));
}

void	ft_looping(t_map *map)
{
	int			idx;
	t_polygon	p;
	t_polygon	p_scaled;
	t_polygon	p_transl;
	t_polygon	p_rot;
	float mx;
	float my;

	idx = 0;
	ft_mlx_clear(map->meta.width, map->meta.height, map->meta, ft_color_new(0x0, 0x0, 0x0));
	while (idx < map->width * map->height)
	{
		p = (t_polygon){
			.p1 = map->vert_pool[map->faces[idx].p1],
			.p2 = map->vert_pool[map->faces[idx].p2],
			.p3 = map->vert_pool[map->faces[idx].p3]
		};
		p_scaled = ft_poly_scale(p, ft_vec3(map->state.scale, map->state.scale, map->state.scale));
		mx = map->state.scale * map->width * 0.5f;
		my = map->state.scale * map->height * 0.5f;
		//scale z
		t_polygon p_scaled_z = ft_poly_scale(p_scaled, ft_vec3(1, 1, map->state.scale_z));
		//translate to center
		p_transl = ft_poly_translate(p_scaled_z, ft_vec3(map->state.translate_x + map->meta.width * 0.5f - mx, map->state.translate_y + map->meta.height * 0.5f - my, 0));
		p_rot = ft_rotate_polygon_isometric(p_transl, map->state.rotate_x, map->state.rotate_y, (t_vec2){.x = map->state.translate_x + map->meta.width * 0.5f, .y = map->state.translate_y + map->meta.height * 0.5f});
		ft_outline_polygon(p_rot, map->meta);
		idx++;
	}
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.window, map->mlx.image, 0, 0);
}
