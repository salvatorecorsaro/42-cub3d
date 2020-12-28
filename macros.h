/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:30:46 by scorsaro          #+#    #+#             */
/*   Updated: 2020/09/24 11:30:49 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define TRUE 1
# define FALSE 0

# ifdef __APPLE__
#  define ESC 53
#  define FORWARD 13
#  define BACK 1
#  define LEFT 0
#  define RIGHT 2
#  define TURNLEFT 123
#  define TURNRIGHT 124
#  define SPRINT 257
#  define APPLE 1
#  define LINUX 0
# endif

# ifdef __linux__
#  define ESC 65307
#  define FORWARD 119
#  define BACK 115
#  define LEFT 97
#  define RIGHT 100
#  define TURNLEFT 65361
#  define TURNRIGHT 65363
#  define SPRINT 65505
#  define APPLE 0
#  define LINUX 1
# endif

# define PRESS_EVENT 2
# define PRESS_MASK 1
# define RELEASE_EVENT 3
# define RELEASE_MASK 2
# define EXIT_EVENT 17
# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.03

# define ERROR_RESOLUTION "Error\nWrong resolution."
# define ERROR_TEXTURES "Error\nThere is a problem parsing textures."
# define ERROR_SPRITE "Error\nThere is a problem with the sprite."
# define ERROR_FLOOR "Error\nThere is a problem with the floor color."
# define ERROR_CEILING "Error\nThere is a problem with the ceiling."
# define ERROR_MAP "Error\nThere is a problem parsing map."
# define ERROR_START_POSITION "Error\nThere is a problem with the player."
# define ERROR_DOT_XPM "Error\nTexture or sprite is not a .xpm file."
# define ERROR_TEXTURE_OPEN "Error\nTexture open."
# define ERROR_TOO_MANY_TEXTURES "Error\nTexture already assigned."
# define ERROR_COLORS "Error\nError during sky or floor color parsing."
# define ERROR_MULTIPLE_RESOLUTIONS "Error\nMultiple resolutions."
# define ERROR_MLX_INIT "Error\nError during mlx_init()."
# define ERROR_DOT_CUB "Error\nMissing .cub."
# define ERROR_HELP "Help\nUse ./cub3d map.cub or ./cub3d map.cub --save."
# define ERROR_WRONG_USAGE "Error\n./cub3d map.cub or ./cub3d map.cub --save."
# define ERROR_MALLOC "Error\n Malloc failed."
# define ERROR_RES_MUL_VAL "Error\nResolution has invalid values."

# define VALID_SIGN "02NSEW"
# define MIN_WIDTH 800
# define MAX_WIDTH 1920
# define MIN_HEIGHT 600
# define MAX_HEIGHT 1080

#endif
