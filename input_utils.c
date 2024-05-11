/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:01:48 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/10 17:38:40 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

int	ft_is_translation_key_pressed(int keycode)
{
	return (keycode == XK_w || \
			keycode == XK_s || \
			keycode == XK_a || \
			keycode == XK_d);
}

int	ft_is_scale_key_pressed(int keycode)
{
	return (keycode == XK_equal || \
			keycode == XK_minus || \
			keycode == XK_z || \
			keycode == XK_x);
}

int	ft_is_rotation_key_pressed(int keycode)
{
	return (keycode == XK_Up || \
			keycode == XK_Down || \
			keycode == XK_Left || \
			keycode == XK_Right || \
			keycode == XK_n || \
			keycode == XK_m);
}

t_ivec2	ft_ivec2(int x, int y)
{
	t_ivec2	v;

	v = (t_ivec2){
		.x = x,
		.y = y,
	};
	return (v);
}

t_dcolor	ft_colord(t_color c1, t_color c2)
{
	t_dcolor	c;

	c = (t_dcolor){
		.c1 = c1,
		.c2 = c2,
	};
	return (c);
}
