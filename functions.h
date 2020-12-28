/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:29:43 by scorsaro          #+#    #+#             */
/*   Updated: 2020/10/01 20:32:29 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void			init(t_all *s, char *arg);
void			init_cube(t_all *s);
void			init_move(t_all *s);
void			parse_dot_cub_file(t_cub *cub, char *file_to_parse);
void			ft_select(char *line, t_cub *cub);
void			get_size(char *line, t_cub *cub);
int				verif_size(char *str, int index);
t_texture		*get_texture(char *line, t_cub *cub, t_texture *texture);
int				check_textures(char *line, int index);
void			index_sprite(t_all *s);
void			get_sprite(char **map, t_cub *cub);
int				get_color(char *line, int index);
void			get_map(char *line, t_cub *cub);
void			ft_free_matrice(char **map);
int				check_map(t_cub *cub);
void			check_parse_error(t_cub *cub);
int				check_square(char **row, int i, int j);
int				ft_ismap(char x);
void			get_player_direction(t_cub *cub, char c);
void			get_player_position(char **map, t_cub *cub);
void			process_res_digits(char *line, t_cub *cub, int i);
int				ft_press(int keycode, t_move *move);
int				ft_release(int keycode, t_move *move);
int				quit(t_all *s);
int				game_loop(t_all *s);
void			destroy_textures(t_all *s);
void			init_raycast(t_all *s, int x);
void			calc_step_dist(t_all *s);
void			dda(t_all *s);
int				raycast(t_all *s);
void			wall_size(t_all *s);
void			write_img(t_all *s, int draw_start, int draw_end, int x);
int				textures_wall(t_all *s, int i, int x, int draw_start);
void			calc_vars(t_all *s, int i);
void			get_right_texture(t_all *s);
void			manage_sprite(t_all *s);
void			sprite_orientation(t_all *s);
void			sort_sprite(t_all *s);
void			draw_sprite(t_all *s, int j);
void			init_sprite(t_all *s, int i);
void			turn_left_right(t_cub *cub, int direction);
void			move_left_right(t_all *s, int direction);
void			move_front_back(t_all *s, int direction);
int				ft_move(t_all *s);
void			take_screenshot(t_all *s);
void			rot_sx(t_cub *cub, double o_d_x, double o_p_x, float sp_rot);
void			check_param(int argc, char **argv);
void			ft_error(char *error_code);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
char			*ft_strnstr(const char *big, const char *needle, size_t len);
int				ft_strlen(const char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strdup(const char *src);
int				ft_isdigit(int c);
int				ft_atoi(char const *str);
void			*ft_memset(void *b, int c, size_t len);
int				ft_isalpha(int c);
void			ft_bzero(void *s, size_t n);
int				find_char_in_str(char *str, char c);
int				get_next_line(int fd, char **line);
char			*stock_trim(char *stock);
char			*get_line(char *stock);
char			*buf_join(char *stock, char *buf);
int				newline_check(char *stock, int read_size);
char			*gnl_error(char *stock);
int				skip_spaces(char *line, int index);

#endif
