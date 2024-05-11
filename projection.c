/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:24:00 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/11 20:38:48 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

t_polygon	ft_project(t_polygon p)
{
	t_polygon	r;

	r = (t_polygon){
		.p1 = ft_translate_point(p.p1, ft_vec3(0, -p.p1.z, 0)),
		.p2 = ft_translate_point(p.p2, ft_vec3(0, -p.p2.z, 0)),
		.p3 = ft_translate_point(p.p3, ft_vec3(0, -p.p3.z, 0))
	};
	return (r);
}

t_polygon	ft_poly_new(t_point p1, t_point p2, t_point p3)
{
	t_polygon	p;

	p = (t_polygon){
		.p1 = p1,
		.p2 = p2,
		.p3 = p3
	};
	return (p);
}

t_state	ft_state_isometric(void)
{
	t_state	state;

	state = (t_state){
		.scale = 25.0f,
		.scale_z = -0.1f,
		.translate_x = 0,
		.translate_y = 0,
		.rotate_x = ft_deg_to_radians(0),
		.rotate_z = ft_deg_to_radians(30),
		.rotate_y = ft_deg_to_radians(0),
	};
	return (state);
}

t_state	ft_state_orthographic(void)
{
	t_state	state;

	state = (t_state){
		.scale = 25.0f,
		.scale_z = -0.1f,
		.translate_x = 0,
		.translate_y = 0,
		.rotate_x = ft_deg_to_radians(45),
		.rotate_z = ft_deg_to_radians(0),
		.rotate_y = ft_deg_to_radians(0),
	};
	return (state);
}
