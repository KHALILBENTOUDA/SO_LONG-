/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:55:26 by kben-tou          #+#    #+#             */
/*   Updated: 2024/12/26 20:59:15 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_next_line(int fd, t_data *data)
{
	char	*buff;
	int		readed;
	char	*line;

	line = NULL;
	buff = malloc(2);
	if (!buff)
		return (NULL);
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buff, 1);
		if (readed == 0)
			break ;
		buff[readed] = '\0';
		line = ft_strjoin(line, buff);
		if (!line)
			break ;
	}
	free(buff);
	if (line)
		data->newlines = check_newlines(line);
	return (line);
}

int	check_newlines(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

void	ft_map_check(char **check_map, t_data *data)
{
	data->mpa_with = ft_strlen(data->map[0]);
	check_lines(data);
	check_walls(data);
	check_content(data);
	check_locked_spaces(check_map, data);
}

void	read_for_map(char *filename, t_data *data)
{
	char	**check_map;
	int		fd;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		ft_error("invalid file fd", NULL);
	data->map = ft_split(get_next_line(fd, data), '\n');
	if (!data->map || !data->map[0])
		ft_error("map is empty", data->map);
	close(fd);
	fd = open(filename, O_RDWR);
	if (fd < 0)
		ft_error("invalid file fd", data->map);
	check_map = ft_split(get_next_line(fd, data), '\n');
	if (!check_map || !check_map[0])
		ft_error("problem in map check!", data->map);
	close(fd);
	ft_map_check(check_map, data);
	ft_free(check_map);
}
