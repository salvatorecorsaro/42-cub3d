/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:28:56 by scorsaro          #+#    #+#             */
/*   Updated: 2020/09/24 11:29:02 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_2020_CUB3D_H
# define CUB3D_2020_CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>

# ifdef __linux__
#  include "mlx/linux/mlx.h"
# endif

# ifdef __APPLE__
#  include "mlx/apple/mlx.h"
# endif

# include "structs.h"
# include "functions.h"
# include "macros.h"

#endif
