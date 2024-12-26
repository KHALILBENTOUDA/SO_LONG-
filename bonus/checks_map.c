/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:58:47 by kben-tou          #+#    #+#             */
/*   Updated: 2024/12/26 20:59:32 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_player_position(char **map, int *x, int *y, char find)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == find)
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	floodfill(char **map, int x, int y, t_data *data)
{
	int	hight;
	int	with;

	hight = data->mpa_hight;
	with = data->mpa_with;
	if (map[y][x] == 'E')
		map[y][x] = 'X';
	if (x < 0 || x >= with || y < 0 || y >= hight || \
		map[y][x] == '1' || map[y][x] == '.' || \
		map[y][x] == 'X' || map[y][x] == 'E' || map[y][x] == 'M')
		return ;
	map[y][x] = '.';
	floodfill(map, x + 1, y, data);
	floodfill(map, x - 1, y, data);
	floodfill(map, x, y + 1, data);
	floodfill(map, x, y - 1, data);
}

void	compare_map_items(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				ft_free(data->map);
				ft_error("invalid map: you can't reach all collections", map);
			}
			else if (map[i][j] == 'E')
			{
				ft_free(data->map);
				ft_error("invalid map: you can't reach the door", map);
			}
			j++;
		}
		i++;
	}
}

void	check_locked_spaces(char **check_map, t_data *data)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	get_player_position(check_map, &x, &y, 'P');
	floodfill(check_map, x, y, data);
	compare_map_items(check_map, data);
}

int	is_validata_image(char *path)
{
	int		fd;

	fd = open(path, O_RDWR);
	if (fd < 0)
		return (0);
	return (fd);
}
