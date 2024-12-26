/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:13:03 by kben-tou          #+#    #+#             */
/*   Updated: 2024/12/26 20:08:06 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish_game(t_data *data, char c)
{
	if (c == 'E')
		write(1, "Congratulations!\n", 17);
	ft_close(data);
}

void	init_image(t_data *data)
{
	if (!is_validata_image("./images/planks.xpm") \
	|| !is_validata_image("./images/acid.xpm") \
	|| !is_validata_image("./images/door1.xpm") \
	|| !is_validata_image("./images/collec.xpm") \
	|| !is_validata_image("./images/ply1.xpm") \
	|| !is_validata_image("./images/ply2.xpm") \
	|| !is_validata_image("./images/ply_v1.xpm") \
	|| !is_validata_image("./images/ply_v2.xpm"))
		ft_error("image path not valid", data->map);
	data->wall = mlx_xpm_file_to_image(data->mlx, \
		"./images/planks.xpm", &data->pix, &data->pix);
	data->space = mlx_xpm_file_to_image(data->mlx, \
		"./images/acid.xpm", &data->pix, &data->pix);
	data->exit = mlx_xpm_file_to_image(data->mlx, \
		"./images/door1.xpm", &data->pix, &data->pix);
	data->collection = mlx_xpm_file_to_image(data->mlx, \
		"./images/collec.xpm", &data->pix, &data->pix);
	data->player = mlx_xpm_file_to_image(data->mlx, \
		"./images/ply1.xpm", &data->pix, &data->pix);
}

void	moving_player(t_data *data, char *moveup, char *moverdown)
{
	static int	i;
	static int	pos;

	if (i == 1000)
		i = 0;
	if (i % 12 == 0)
	{
		if (pos == 1)
		{
			pos = 0;
			data->player = mlx_xpm_file_to_image(data->player, \
				moveup, &data->mpa_with, &data->mpa_hight);
		}
		else
		{
			pos = 1;
			data->player = mlx_xpm_file_to_image(data->player, \
				moverdown, &data->mpa_with, &data->mpa_hight);
		}
	}
	i++;
}

void	check_and_put(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win, \
		data->space, data->pix * j, data->pix * i);
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->wall, data->pix * j, data->pix * i);
	if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->exit, data->pix * j, data->pix * i);
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->collection, data->pix * j, data->pix * i);
	if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->player, data->pix * j, data->pix * i);
}

int	put_image(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	if (data->position == 1)
		moving_player(data, "./images/ply_v1.xpm", \
			"./images/ply_v2.xpm");
	else
		moving_player(data, "./images/ply1.xpm", \
			"./images/ply2.xpm");
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			check_and_put(data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}