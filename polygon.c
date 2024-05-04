/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:59:41 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/04 17:01:16 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

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

t_polygon	ft_poly_translate(t_polygon p, t_vec3 t)
{
	t_polygon r;

	r = (t_polygon){
		.p1 = ft_translate_point(p.p1, t),
		.p2 = ft_translate_point(p.p2, t),
		.p3 = ft_translate_point(p.p3, t),
	};
	return (r);
}

t_polygon	ft_poly_scale(t_polygon p, t_vec3 t)
{
	t_polygon r;

	r = (t_polygon){
		.p1 = ft_scale_point(p.p1, t),
		.p2 = ft_scale_point(p.p2, t),
		.p3 = ft_scale_point(p.p3, t),
	};
	return (r);
}

t_polygon	ft_rotate_poly_x(t_polygon p, float ang)
{
	t_polygon	r;

	r = (t_polygon){
		.p1 = ft_rotate_x(p.p1, ang),
		.p2 = ft_rotate_x(p.p2, ang),
		.p3 = ft_rotate_x(p.p3, ang)
	};
	return (r);
}

t_polygon	ft_rotate_poly_y(t_polygon p, float ang)
{
	t_polygon	r;

	r = (t_polygon){
		.p1 = ft_rotate_y(p.p1, ang),
		.p2 = ft_rotate_y(p.p2, ang),
		.p3 = ft_rotate_y(p.p3, ang)
	};
	return (r);
}
