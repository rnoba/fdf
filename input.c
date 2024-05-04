/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:05:41 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/04 17:01:33 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	ft_handle_input(int keycode, t_map *map)
{
	if (keycode == 65307)
	{
		mlx_loop_end(map->mlx.ptr);
	} else if (keycode == 61)
	{
		map->state.scale += 0.2f;
	} else if (keycode == 45)
	{
		map->state.scale -= 0.2f;
	}
	else if (keycode == XK_w)
	{
		map->state.translate_y -= 3.0f;
	}
	else if (keycode == XK_s)
	{
		map->state.translate_y += 3.0f;
	}
	else if (keycode == XK_d)
	{
		map->state.translate_x += 3.0f;
	}
	else if (keycode == XK_a)
	{
		map->state.translate_x -= 3.0f;
	}
	else if (keycode == XK_z)
	{
		map->state.scale_z += .1f;
	}
	else if (keycode == XK_x)
	{
		map->state.scale_z -= .2f;
	}
	else if (keycode == XK_t)
	{
		map->state.theta -= 0.0174533;
	}
	else if (keycode == XK_y)
	{
		map->state.theta += 0.0174533;
	} else if (keycode == 65361)
	{
		map->state.rotate_y += 0.05f;
	} else if (keycode == 65363)
	{
		map->state.rotate_y -= 0.05f;
	} else if (keycode == 65362)
	{
		map->state.rotate_x += 0.05f;
	} else if (keycode == 65364)
	{
		map->state.rotate_x -= 0.05f;
	}
}
