/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:21:13 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/04 17:16:35 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

t_point	ft_scale_point(t_point p, t_vec3 scaling)
{
	t_point	r;

	r = (t_point){
		.x = p.x * scaling.x,
		.y = p.y * scaling.y,
		.z = p.z * scaling.z,
		.color = p.color
	};
	return (r);
}

t_point	ft_translate_point(t_point p, t_vec3 translation)
{
	t_point	r;

	r = (t_point){
		.x = p.x + translation.x,
		.y = p.y + translation.y,
		.z = p.z + translation.z,
		.color = p.color
	};
	return (r);
}

t_point	ft_rotate_x(t_point p, float ang)
{
	t_point	r;

	r = (t_point){
		.x = p.x,
		.y = p.y * cosf(ang) - p.z * sinf(ang),
		.z = p.y * sinf(ang) + p.z * cosf(ang),
		.color = p.color
	};
	return (r);
}

t_point	ft_rotate_y(t_point p, float ang)
{
	t_point	r;

	r = (t_point){
		.x = p.x * cosf(ang) + p.z * sinf(ang),
		.y = p.y,
		.z = p.x * sinf(ang) - p.z * cosf(ang),
		.color = p.color
	};
	return (r);
}

t_point	ft_rotate_z(t_point p, float ang)
{
	t_point	r;

	r = (t_point){
		.x = p.x * cosf(ang) - p.y * sinf(ang),
		.y = p.x * sinf(ang) + p.y * cosf(ang),
		.z = p.z,
		.color = p.color
	};
	return (r);
}
