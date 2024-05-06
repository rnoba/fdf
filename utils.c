/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:36:07 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/04 17:09:45 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

//TODO(refactoring)

void	ft_assert(int pred, const char *error_msg)
{
	if (!pred)
	{
		ft_putstr_fd((char *)error_msg, 2);
		exit(1);
	}
}

int	ft_strflen(char *str, int (*f)(int))
{
	int	size;

	size = 0;

	while (str && *str && !f(*str))
	{
		size++;
		str++;
	}
	return (size);
}

char	*ft_strcfchr(char *s, int c, int (*f)(int), int l)
{
	int	idx;

	idx = -1;
	while (s[++idx] && idx < l)
	{
		if (s[idx] == (unsigned char) c && f(s[idx-1]))
		{
			return ((char *)&(s[idx]));
		}
	}
	return (NULL);
}

t_color	ft_color_default(void)
{
	t_color	c;

	c = (t_color){
		.r = 0xFF,
		.g = 0xFF,
		.b = 0xFF
	};
	return (c);
}

t_color	ft_color_new(int r, int g, int b)
{
	t_color	c;

	c = (t_color){
		.r = r,
		.g = g,
		.b = b 
	};
	return (c);
}

int	ft_get_map_width(char *line)
{
	int	size;
	char *aux;

	aux = ft_strfchr(line, ft_isdigit);
	size = 0;
	while (aux)
	{
		aux = ft_strfchr(ft_strfchr(aux, ft_isspace), ft_isdigit);
		size++;
	}
	return (size);
}

int	ft_get_map_height(const char *filename)
{
	char	*line;
	int		size;
	int		fd;

	ft_assert((fd = open(filename, O_RDONLY)) != -1, strerror(errno));
	line = get_next_line(fd);
	size = 0;
	while (line)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (size);
}

t_state	ft_state_isometric(void)
{
	t_state state;

	state = (t_state){
		.scale = 10.0f,
		.scale_z = -0.5f,
		.translate_x = 0,
		.translate_y = 0,
		.rotate_x = ft_deg_to_radians(-17), 
		.rotate_z = ft_deg_to_radians(-42), 
		.rotate_y = ft_deg_to_radians(-17), 
	};
	return (state);
}

t_state	ft_state_orthographic(void)
{
	t_state state;

	state = (t_state){
		.scale = 10.0f,
		.scale_z = -0.5f,
		.translate_x = 0,
		.translate_y = 0,
		.rotate_x = ft_deg_to_radians(45), 
		.rotate_z = ft_deg_to_radians(0), 
		.rotate_y = ft_deg_to_radians(0), 
	};
	return (state);
}
