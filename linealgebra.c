/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linealgebra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:56:19 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/01 15:21:23 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

t_vec3	ft_vec3(float x, float y, float z)
{
	t_vec3	vec;

	vec = (t_vec3){
		.x = x,
		.y = y,
		.z = z
	};
	return (vec);
}

float	ft_deg_to_radians(float deg)
{
	return ((deg / 180.0f) * M_PI);
}

float	ft_rad_to_deg(float rad)
{
	return ((rad * 180.0f) / M_PI);
}

float	ft_pytagorean_dist(t_vec3 start, t_vec3 end, t_vec3 curr)
{
	float	dx;
	float	dy;
	float	x;
	float	y;
	float	total_dist;

	dx = (end.x - start.x);
	dy = (end.y - start.y);
	total_dist = sqrtf(dx * dx + dy * dy);
	x = (end.x - curr.x) * (end.x - curr.x);
	y = (end.y - curr.y) * (end.y - curr.y);
	if (total_dist > 0.0f)
	{
		return (sqrtf(x + y) / total_dist);
	}
	return (0);
}
