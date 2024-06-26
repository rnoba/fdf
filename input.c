/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:22:08 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/11 20:30:38 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	ft_handle_input(int kc, t_map *map)
{
	float	*rx;
	float	*ry;
	float	*rz;

	rz = &map->state.rotate_z;
	ry = &map->state.rotate_y;
	rx = &map->state.rotate_x;
	if (kc == XK_Escape)
		mlx_loop_end(map->mlx.ptr);
}
