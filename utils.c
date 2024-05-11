/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:36:07 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/10 18:06:34 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

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
		if (s[idx] == (unsigned char) c && f(s[idx - 1]))
		{
			return ((char *)&(s[idx]));
		}
	}
	return (NULL);
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
	int		size;
	char	*aux;

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

	fd = open(filename, O_RDONLY);
	if (!fd)
	{
		ft_putendl_fd(strerror(errno), 2);
		return (0);
	}
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
