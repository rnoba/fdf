/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:00:50 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/11 20:30:45 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

static void	ft_translate(int keycode, float *x, float *y, float v)
{
	int	dir;

	dir = 1;
	if (keycode == XK_w || keycode == XK_a)
		dir = -1;
	if (keycode == XK_w || keycode == XK_s)
		*y += (v * dir);
	else if (keycode == XK_a || keycode == XK_d)
		*x += (v * dir);
}

static void	ft_scale(int keycode, float *scale, float fac)
{
	int	dir;

	dir = 1;
	if (keycode == XK_minus || keycode == XK_z)
		dir = -1;
	if (*scale <= 1.0f && dir == -1 && !(keycode == XK_z || keycode == XK_x))
		fac = 0;
	*scale += (fac * dir);
}

static void	ft_rotate(int keycode, float *yaw, float *pitch, float *roll)
{
	int		dir;
	float	f;

	dir = -1;
	f = 0.09f;
	if (keycode == XK_Left || keycode == XK_Down || keycode == XK_n)
		dir = 1;
	if (keycode == XK_Left || keycode == XK_Right)
		*pitch += (dir * f);
	else if (keycode == XK_Up || keycode == XK_Down)
		*roll += (dir * f);
	else if (keycode == XK_n || keycode == XK_m)
		*yaw += (dir * f);
}

void	ft_projection(int k, t_map *map)
{
	t_state	ortho;
	t_state	iso;

	ortho = ft_state_orthographic();
	iso = ft_state_isometric();
	if (k == XK_o)
	{
		map->state.rotate_x = ortho.rotate_x;
		map->state.rotate_y = ortho.rotate_y;
		map->state.rotate_z = ortho.rotate_z;
	}
	else if (k == XK_i)
	{
		map->state.rotate_x = iso.rotate_x;
		map->state.rotate_y = iso.rotate_y;
		map->state.rotate_z = iso.rotate_z;
	}
}

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
	else if (ft_is_translation_key_pressed(kc))
		ft_translate(kc, &map->state.translate_x, &map->state.translate_y, 2);
	else if (ft_is_scale_key_pressed(kc))
	{
		if (kc == XK_z || kc == XK_x)
			ft_scale(kc, &map->state.scale_z, 0.1f);
		else
			ft_scale(kc, &map->state.scale, 1.0f);
	}
	else if (ft_is_rotation_key_pressed(kc))
		ft_rotate(kc, rz, ry, rx);
	else if (kc == XK_o || kc == XK_i)
		ft_projection(kc, map);
}
