/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:18:17 by kben-tou          #+#    #+#             */
/*   Updated: 2024/12/26 21:02:20 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct data_a
{
	void	*mlx;
	void	*win;
	void	*image;
	char	**map;
	int		mpa_with;
	int		mpa_hight;
	int		p;
	int		c;
	int		e;
	int		f;
	int		o;
	int		m;
	int		pix;
	int		movements;
	int		position;
	void	*wall;
	void	*space;
	void	*exit;
	void	*collection;
	void	*enemy;
	void	*player;
	void	*playe2;
	int		newlines;
}	t_data;

char	**ft_split(char *s, char c);
size_t	ft_strlen(const char *s);
void	ft_error(char *err, char **map);
void	extantion_check(char *filename);
int		ft_strcmp(char *s1, char *s2);
void	ft_map_check(char **check_map, t_data *data);
void	init_image(t_data *data);
int		put_image(t_data *data);
void	ft_move_forward(t_data *data);
void	ft_move_backward(t_data *data);
void	ft_move_up(t_data *data);
void	ft_move_down(t_data *data);
void	ft_free(char **map);
void	check_locked_spaces(char **check_map, t_data *data);
char	*ft_itoa(int n);
void	finish_game(t_data *data, char c);
void	enemy_forward(t_data *data, int x, int y);
void	moving_enemy(t_data *data);
int		ft_key_hook(int keycode, t_data *data);
char	*get_next_line(int fd, t_data *data);
void	read_for_map(char *filename, t_data *data);
void	check_content(t_data *data);
void	check_walls(t_data *data);
void	check_lines(t_data *data);
int		ft_close(t_data *data);
void	get_player_position(char **map, int *x, int *y, char find);
char	*ft_strjoin(char *s1, char *s2);
int		check_newlines(char *str);
int		is_validata_image(char *path);

#endif