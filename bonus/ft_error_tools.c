/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:12:02 by kben-tou          #+#    #+#             */
/*   Updated: 2024/12/26 20:59:26 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	extantion_check(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len >= 4)
	{
		if (ft_strcmp(filename + len - 4, ".ber") != 0)
			ft_error("invalid file name", NULL);
	}
	else
		ft_error("invalid file name", NULL);
}

void	check_walls(t_data *data)
{
	int	i;

	data->mpa_hight = 0;
	if (!data->map[data->mpa_hight])
		ft_error("map is empty", data->map);
	while (data->map[data->mpa_hight])
		data->mpa_hight++;
	i = 0;
	while (data->map[0][i] && data->map[data->mpa_hight - 1][i])
	{
		if (data->map[0][i] != '1' || data->map[data->mpa_hight - 1][i] != '1')
			ft_error("there is a problem in walls", data->map);
		i++;
	}
	i = 0;
	while (i < data->mpa_hight)
	{
		if (data->map[i][0] != '1' || data->map[i][data->mpa_with - 1] != '1')
			ft_error("there is a problem in walls", data->map);
		i++;
	}
	if (data->newlines != data->mpa_hight - 1)
		ft_error("empty lines in map", data->map);
}

void	check_lines(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (data->mpa_with != j)
			ft_error("invalid map lines", data->map);
		i++;
	}
}

void	items(t_data *data, int i)
{
	int		j;

	j = 0;
	while (j < data->mpa_with)
	{
		if (data->map[i][j] == '0')
			data->o++;
		else if (data->map[i][j] == 'P')
			data->p++;
		else if (data->map[i][j] == 'C')
			data->c++;
		else if (data->map[i][j] == '1')
			data->f++;
		else if (data->map[i][j] == 'E')
			data->e++;
		else if (data->map[i][j] == 'M')
			data->m++;
		else
			ft_error("invalid map content", data->map);
		j++;
	}
}

void	check_content(t_data *data)
{
	int	i;

	i = 0;
	data->o = 0;
	data->f = 0;
	data->c = 0;
	data->p = 0;
	data->e = 0;
	data->m = 0;
	while (i < data->mpa_hight)
	{
		items(data, i);
		i++;
	}
	if (data->e != 1 || data->p != 1 || data->c == 0 \
		|| data->o == 0 || data->m == 0)
		ft_error("invalid map content", data->map);
}
