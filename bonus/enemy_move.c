/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:42:48 by kben-tou          #+#    #+#             */
/*   Updated: 2024/12/26 20:59:29 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	moving_enemy(t_data *data)
{
	static int	j;
	static int	pos;

	if (j == 1000)
		j = 0;
	if (j % 5 == 0)
	{
		if (pos == 1)
		{
			pos = 0;
			data->enemy = mlx_xpm_file_to_image(data->enemy, \
			"./images/enemyv1.xpm", &data->mpa_with, &data->mpa_hight);
		}
		else
		{
			pos = 1;
			data->enemy = mlx_xpm_file_to_image(data->enemy, \
			"./images/enemyv2.xpm", &data->mpa_with, &data->mpa_hight);
		}
	}
	j++;
}

void	move_for(t_data *data, int x, int y)
{
	if (data->map[y][x + 1] == 'P')
		finish_game(data, 'M');
	data->map[y][x] = '0';
	data->map[y][x + 1] = 'M';
}

void	move_back(t_data *data, int x, int y)
{
	if (data->map[y][x - 1] == 'P')
		finish_game(data, 'M');
	data->map[y][x] = '0';
	data->map[y][x - 1] = 'M';
}

void	enemy_forward(t_data *data, int x, int y)
{
	static int	direction;
	static int	i;

	if (i == 15)
	{
		if (direction == 1)
		{
			if (data->map[y][x + 1] == '0' || data->map[y][x + 1] == 'P')
				move_for(data, x, y);
			else
				direction = -1;
		}
		else
		{
			if (data->map[y][x - 1] == '0' || data->map[y][x - 1] == 'P')
				move_back(data, x, y);
			else
				direction = 1;
		}
		i = 0;
	}
	i++;
}
