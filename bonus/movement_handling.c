/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:40:54 by kben-tou          #+#    #+#             */
/*   Updated: 2024/12/26 20:59:01 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		ft_close(data);
	else if (keycode == 0)
		ft_move_backward(data);
	else if (keycode == 1)
		ft_move_down(data);
	else if (keycode == 2)
		ft_move_forward(data);
	else if (keycode == 13)
		ft_move_up(data);
	return (0);
}

void	ft_move_forward(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_player_position(data->map, &x, &y, 'P');
	if (data->map[y][x + 1] == '0')
	{
		data->map[y][x] = '0';
		data->map[y][x + 1] = 'P';
		data->movements++;
	}
	if (data->map[y][x + 1] == 'C')
	{
		data->map[y][x] = '0';
		data->map[y][x + 1] = 'P';
		data->c -= 1;
		data->movements++;
	}
	data->player = mlx_xpm_file_to_image(data->mlx, \
		"./images/ply1.xpm", &data->pix, &data->pix);
	(1) && (data->position = 0, put_image(data));
	if ((data->map[y][x + 1] == 'E' && data->c == 0) \
		|| data->map[y][x + 1] == 'M')
		finish_game(data, data->map[y][x + 1]);
}

void	ft_move_backward(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_player_position(data->map, &x, &y, 'P');
	if (data->map[y][x - 1] == '0')
	{
		data->map[y][x] = '0';
		data->map[y][x - 1] = 'P';
		data->movements++;
	}
	if (data->map[y][x - 1] == 'C')
	{
		data->map[y][x] = '0';
		data->map[y][x - 1] = 'P';
		data->c -= 1;
		data->movements++;
	}
	data->player = mlx_xpm_file_to_image(data->mlx, \
		"./images/ply_v1.xpm", &data->pix, &data->pix);
	(1) && (data->position = 1, put_image(data));
	if ((data->map[y][x - 1] == 'E' && data->c == 0) \
		|| data->map[y][x - 1] == 'M')
		finish_game(data, data->map[y][x - 1]);
}

void	ft_move_down(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_player_position(data->map, &x, &y, 'P');
	if (data->map[y + 1][x] == '0')
	{
		data->map[y][x] = '0';
		data->map[y + 1][x] = 'P';
		data->movements++;
	}
	if (data->map[y + 1][x] == 'C')
	{
		data->map[y][x] = '0';
		data->map[y + 1][x] = 'P';
		data->c -= 1;
		data->movements++;
	}
	put_image(data);
	if ((data->map[y + 1][x] == 'E' && data->c == 0) \
		|| data->map[y + 1][x] == 'M')
		finish_game(data, data->map[y + 1][x]);
}

void	ft_move_up(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_player_position(data->map, &x, &y, 'P');
	if (data->map[y - 1][x] == '0')
	{
		data->map[y][x] = '0';
		data->map[y - 1][x] = 'P';
		data->movements++;
	}
	if (data->map[y - 1][x] == 'C')
	{
		data->map[y][x] = '0';
		data->map[y - 1][x] = 'P';
		data->c -= 1;
		data->movements++;
	}
	put_image(data);
	if ((data->map[y - 1][x] == 'E' && data->c == 0) \
		|| data->map[y - 1][x] == 'M')
		finish_game(data, data->map[y - 1][x]);
}
