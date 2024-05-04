/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:31:29 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/04 17:00:54 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <libft.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <limits.h>
# include <X11/XKBlib.h>
# include <X11/keysym.h>

typedef struct s_mlx {
	void	*ptr;
	void	*window;
	void	*image;
}	t_mlx;

typedef struct s_vec2 {
	float	x;
	float	y;
}	t_vec2;

typedef struct s_meta {
	char	*buffer;
	int		bpp;
	int		sl;
	int		end;
	int		width;
	int		height;
}	t_meta;

typedef struct s_color {
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vec3 {
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_point {
	float	x;
	float	y;
	float	z;
	t_color	color;
}	t_point;

typedef struct s_state {
	float	scale;
	float	scale_z;
	float	translate_x;
	float	translate_y;
	float	rotate_x;
	float	rotate_y;
	float	theta;
}	t_state;

typedef struct s_faces {
	int	p1;
	int	p2;
	int	p3;
}	t_faces;

typedef struct s_map {
	const char	*file;
	t_faces		*faces;
	t_point		*vert_pool;
	t_state		state;
	t_meta		meta;
	t_mlx		mlx;
	int			width;
	int			height;
}	t_map;

typedef struct s_polygon {
	t_point	p1;
	t_point	p2;
	t_point	p3;
}	t_polygon;

t_polygon	ft_poly_new(t_point p1, t_point p2, t_point p3);
t_polygon	ft_poly_scale(t_polygon p, t_vec3 t);
t_polygon	ft_poly_translate(t_polygon p, t_vec3 t);
t_polygon	ft_rotate_poly_x(t_polygon p, float theta);
t_polygon	ft_rotate_poly_y(t_polygon p, float ang);
t_polygon	ft_rotate_poly_z(t_polygon p, float ang);
t_polygon	ft_isometric_projection(t_polygon p, float theta);
t_polygon	ft_perspective_projection(t_polygon p, float theta);

t_point		ft_translate_point(t_point p, t_vec3 translation);
t_point		ft_scale_point(t_point p, t_vec3 translation);
t_point		ft_rotate_x(t_point p, float ang);
t_point		ft_rotate_y(t_point p, float ang);
t_point		ft_rotate_z(t_point p, float ang);
t_point		ft_div_point(t_point p, float z);

t_vec3		ft_vec3(float x, float y, float z);

t_state		ft_empty_state(void);

t_color		ft_lerpcolor(t_color start, t_color end, float t);
t_color		ft_color_new(int r, int g, int b);
t_color		ft_parse_color(char *c, int len);
t_color		ft_color_default(void);

t_faces		*ft_mount_faces(int w, int h);

void		ft_mlx_clear(int width, int height, t_meta meta, t_color c);
void		ft_outline_polygon(t_polygon poly, t_meta meta);
void		ft_handle_input(int keycode, t_map *map);
void		ft_assert(int pred, const char *error_msg);
void		ft_parse_map(t_map	*map);
void		ft_looping(t_map *state);

char		*ft_strcfchr(char *s, int c, int (*f)(int), int l);

int			ft_get_map_width(char *line);
int			ft_strflen(char *str, int (*f)(int));
int			ft_get_map_height(const char *filename);

float		ft_pytagorean_dist(t_vec3 start, t_vec3 end, t_vec3 curr);
float		ft_lerp(float a, float b, float t);

#endif
