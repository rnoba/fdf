/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:42:26 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/10 17:58:27 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	ft_paint(t_dcolor c, t_ivec2 p0, t_meta meta, float p)
{
	if (p0.x < meta.width && p0.y < meta.height && p0.x > 0 && p0.y > 0)
	{
		ft_pixel_put(p0, meta, ft_lerpcolor(c.c1, c.c2, p));
	}
}

void	ft_init_bres(t_ivec2 *p0, t_ivec2 *p1, t_ivec2 *s, t_ivec2 *d)
{
	d->x = abs(p1->x - p0->x);
	d->y = -abs(p1->y - p0->y);
	s->y = 1;
	s->x = 1;
	if (p0->x > p1->x)
		s->x = -1;
	if (p0->y > p1->y)
		s->y = -1;
}
