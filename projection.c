/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:24:00 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/01 16:58:29 by rnogueir         ###   ########.fr       */
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
