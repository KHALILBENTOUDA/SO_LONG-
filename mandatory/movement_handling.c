/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:40:54 by kben-tou          #+#    #+#             */
/*   Updated: 2024/12/30 20:04:00 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		(1) && (ft_putnbr(++data->movements), write(1, "\n", 1));
	}
	if (data->map[y][x + 1] == 'C')
	{
		data->map[y][x] = '0';
		data->map[y][x + 1] = 'P';
		data->c -= 1;
		(1) && (ft_putnbr(++data->movements), write(1, "\n", 1));
	}
	data->player = mlx_xpm_file_to_image(data->mlx, \
		"./images/ply1.xpm", &data->pix, &data->pix);
	(1) && (data->position = 0, put_image(data));
	if (data->map[y][x + 1] == 'E' && data->c == 0)
		finish_game(data, 'E');
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
		(1) && (ft_putnbr(++data->movements), write(1, "\n", 1));
	}
	if (data->map[y][x - 1] == 'C')
	{
		data->map[y][x] = '0';
		data->map[y][x - 1] = 'P';
		data->c -= 1;
		(1) && (ft_putnbr(++data->movements), write(1, "\n", 1));
	}
	data->player = mlx_xpm_file_to_image(data->mlx, \
		"./images/ply_v1.xpm", &data->pix, &data->pix);
	(1) && (data->position = 1, put_image(data));
	if (data->map[y][x - 1] == 'E' && data->c == 0)
		finish_game(data, 'E');
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
		(1) && (ft_putnbr(++data->movements), write(1, "\n", 1));
	}
	if (data->map[y + 1][x] == 'C')
	{
		data->map[y][x] = '0';
		data->map[y + 1][x] = 'P';
		data->c -= 1;
		(1) && (ft_putnbr(++data->movements), write(1, "\n", 1));
	}
	put_image(data);
	if (data->map[y + 1][x] == 'E' && data->c == 0)
		finish_game(data, 'E');
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
		(1) && (ft_putnbr(++data->movements), write(1, "\n", 1));
	}
	if (data->map[y - 1][x] == 'C')
	{
		data->map[y][x] = '0';
		data->map[y - 1][x] = 'P';
		(1) && (ft_putnbr(++data->movements), write(1, "\n", 1));
	}
	put_image(data);
	if (data->map[y - 1][x] == 'E' && data->c == 0)
		finish_game(data, 'E');
}
