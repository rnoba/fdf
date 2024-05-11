/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:21:15 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/10 18:08:53 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

void	ft_assert(int pred, const char *error_msg, t_mlx *mlx)
{
	if (!pred)
	{
		ft_putendl_fd((char *)error_msg, 2);
		if (mlx->ptr)
			mlx_loop_end(mlx->ptr);
	}
}

t_mlx	ft_init_mlx(t_meta *meta)
{
	t_mlx	mlx;

	meta->width = 800;
	meta->height = 600;
	ft_assert((mlx.ptr = mlx_init()) != NULL, "ERROR: failed to init mlx\n",
		&mlx);
	mlx_get_screen_size(mlx.ptr, &meta->width, &meta->height);
	ft_assert((mlx.window = mlx_new_window(mlx.ptr,
				meta->width, meta->height, "fdf")) != NULL \
			, "ERROR: failed to create window\n", &mlx);
	ft_assert((mlx.image = mlx_new_image(mlx.ptr,
				meta->width, meta->height), &mlx) != NULL, \
			"ERROR: failed to create image\n", &mlx);
	meta->buffer = mlx_get_data_addr(mlx.image,
			&meta->bpp, &meta->sl, &meta->end);
	return (mlx);
}

void	ft_destroy_mlx(t_mlx *m)
{
	if (!m || !m->ptr)
		return ;
	if (m->window)
	{
		if (m->image)
		{
			mlx_destroy_image(m->ptr, m->image);
		}
		mlx_destroy_window(m->ptr, m->window);
	}
	mlx_destroy_display(m->ptr);
}

void	ft_mlx_terminate(t_mlx *mlx)
{
	mlx_loop_end(mlx->ptr);
}

int	main(int ac, char *av[])
{
	t_map	map;

	if (ac != 2)
		ft_putendl_fd("Usage: fdf [mapname]", 2);
	map.mlx = ft_init_mlx(&map.meta);
	map.file = av[ac - 1];
	map.state = ft_state_isometric();
	map.height = ft_get_map_height(map.file);
	ft_parse_map(&map);
	map.faces = ft_mount_faces(map.width, map.height);
	mlx_loop_hook(map.mlx.ptr, (int (*)())ft_looping, (void *)&map);
	mlx_hook(map.mlx.window, DestroyNotify,
		NoEventMask, (int (*)())ft_mlx_terminate, (void *)&map.mlx);
	mlx_hook(map.mlx.window, KeyPress,
		KeyPressMask, (int (*)())ft_handle_input, (void *)&map);
	mlx_loop(map.mlx.ptr);
	ft_destroy_mlx(&map.mlx);
	free(map.faces);
	free(map.vert_pool);
	free(map.mlx.ptr);
}
