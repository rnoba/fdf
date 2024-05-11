/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:38:03 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/10 18:09:33 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

t_faces	*ft_mount_faces(int w, int h)
{
	t_faces	*face_pool;
	int		size;
	int		start;

	start = 0;
	size = w * h;
	face_pool = malloc(sizeof(t_faces) * (size));
	while (start < size)
	{
		face_pool[start].p1 = start;
		face_pool[start].p2 = start;
		face_pool[start].p3 = start;
		if ((start + 1) % w > 0)
		{
			face_pool[start].p2 = start + 1;
		}
		if (start < size - (w))
		{
			face_pool[start].p3 = start + w;
		}
		start++;
	}
	return (face_pool);
}

t_point	ft_point_new(float x, float y, float z, t_color color)
{
	t_point	point;

	point = (t_point){
		.x = x,
		.y = y,
		.z = z,
		.color = color
	};
	return (point);
}

int	ft_get_point(char *line, t_point *vertex_pool, int y, int w)
{
	int		x;
	int		z;
	char	*aux;
	char	*cs;
	t_color	color;

	aux = ft_strfchr(line, ft_isdigit);
	x = 0;
	z = 0;
	while (aux)
	{
		cs = ft_strcfchr(aux, ',', ft_isdigit, ft_strflen(aux, ft_isspace));
		color = ft_color_default();
		if (cs)
			color = ft_parse_color(cs + 1, ft_strflen(cs, ft_isspace));
		z = ft_atoi(aux);
		if (x > 0 && ft_isdigit(*aux) && *(aux - 1) == '-')
			z = ft_atoi(aux - 1);
		vertex_pool[y * w + x] = ft_point_new(x, y, z, color);
		aux = ft_strfchr(ft_strfchr(aux, ft_isspace), ft_isdigit);
		x++;
	}
	return (x);
}

void	ft_parse_map(t_map	*map)
{
	char	*line;
	int		ok;
	int		fd;
	int		y;

	ft_assert((fd = open(map->file, O_RDONLY)) != -1, strerror(errno),
		&map->mlx);
	line = get_next_line(fd);
	map->width = ft_get_map_width(line);
	map->vert_pool = malloc(sizeof(t_point) * (map->width * map->height));
	ft_assert((map->vert_pool) != NULL, strerror(errno), &map->mlx);
	y = 0;
	while (line)
	{
		ok = map->width == ft_get_point(line, map->vert_pool, y++, map->width);
		ft_assert((ok && !(map->width == 0)), "Error: invalid line size\n",
			&map->mlx);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
