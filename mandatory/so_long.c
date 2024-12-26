/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:04:15 by kben-tou          #+#    #+#             */
/*   Updated: 2024/12/26 18:23:50 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *err, char **map)
{
	if (map)
		ft_free(map);
	perror(err);
	exit(1);
}

int	hight_count(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_free(data->map);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.pix = 32;
	data.movements = 0;
	if (ac != 2)
		ft_error("invalid number of arguments", NULL);
	extantion_check(av[1]);
	read_for_map(av[1], &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, \
		ft_strlen(data.map[0]) * data.pix, \
		hight_count(data.map) * data.pix, "so_long");
	init_image(&data);
	put_image(&data);
	mlx_hook(data.win, 17, 0, ft_close, &data);
	mlx_key_hook(data.win, ft_key_hook, &data);
	mlx_loop_hook(data.mlx, put_image, &data);
	mlx_loop(data.mlx);
	ft_free(data.map);
	return (0);
}
