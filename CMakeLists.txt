cmake_minimum_required(VERSION 3.17)
project(cub3d_2020 C)

set(CMAKE_C_STANDARD 99)

set(HALIDE_DISTRIB_USE_STATIC_LIBRARY TRUE)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if (LINUX)
    include_directories(mlx/linux)
endif(LINUX)

file(GLOB SRCS "srcs/*.c")

if (LINUX)
    link_libraries(mlx)
    link_libraries(X11)
    link_libraries(m)
    link_libraries(Xext)
endif(LINUX)

add_executable(cub3d_2020 cub3d.c cub3d.h libft.c functions.h checkers.c structs.h macros.h gnl.c structs_initializer.c textures_processing.c map_parsing.c config_parsing.c color_parsing.c raycasting.c sprites.c input.c closing.c movement.c libft_2.c libft_3.c map_parsing_2.c raycasting_2.c save_screenshot.c)