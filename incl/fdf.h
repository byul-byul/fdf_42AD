/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:50:30 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/16 00:26:56 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <string.h>

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# define TRUE				1
# define FALSE				0
# define ERR_MSG_ENABLED	TRUE

# define FILE_EXT			".fdf"

# define ERR_CODE_ARG_COUNT		1
# define ERR_CODE_INVALID_FILE	2
# define ERR_CODE_MEMORY_FAIL	3
# define ERR_CODE_OPEN_FAIL		4
# define ERR_CODE_INVALID_MAP_H	5
# define ERR_CODE_INVALID_MAP_E	6
# define ERR_CODE_INVALID_MAP_R	7
# define ERR_CODE_INVALID_MAP_W	8
# define ERR_CODE_GNL			9

# define ERR_MSG_00	"Error\n"
# define ERR_MSG_01	"ERROR: invalid argument count (Usage: ./fdf map.fdf).\n"
# define ERR_MSG_02	"ERROR: invalid file extension (Usage: ./fdf map.fdf).\n"
# define ERR_MSG_03	"ERROR: invalid file or file does not exist.\n"
# define ERR_MSG_04	"ERROR: invalid map: empty lines are not allowed.\n"
# define ERR_MSG_05	"ERROR: invalid map: map is empty.\n"
# define ERR_MSG_06	"ERROR: invalid map: failed to parse map.\n"
# define ERR_MSG_07	"ERROR: invalid map: failed to read map from file.\n"
# define ERR_MSG_08	"ERROR: invalid map: all rows should have same size.\n"
# define ERR_MSG_09	"ERROR: malloc() failed.\n"

typedef struct s_cell
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_cell;

typedef struct s_map
{
	int		width;
	int		height;
	t_cell	**cells;
	char	*file_path;
}				t_map;

typedef struct s_camera
{
	double	zoom;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	int		offset_x;
	int		offset_y;
	double	height_mod;
}				t_camera;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_mlx;

typedef enum e_proj_type
{
	ISOMETRIC,
	PARALLEL,
	PERSPECTIVE
}			t_proj_type;

typedef struct s_projection
{
	t_proj_type	type;
	void		(*apply_projection)(t_cell *c);
}				t_projection;

typedef struct s_fdf
{
	int				has_allocated_map;
	int				has_allocated_cells;
	int				allocated_cell_count;
	t_map			*map;
	t_camera		camera;
	t_projection	projection;
	t_mlx			mlx;
}				t_fdf;

void	fdf(int ac, char **av);
int		validate_arg(int ac, char **av);
int		init_data(t_fdf *f, char *path);
int		parse_arg(t_fdf *f, char *path);
void	clean_data(t_fdf *f);
int		get_file_line_count(char *path);
int		get_column_count(char *row);
void	print_error(int error_code);
void	clean_cells(t_cell **cells, int count);

// # include <stdio.h>
// # include "libft.h"
// # include "mlx.h"
// # include <errno.h>
// # include <math.h>
// # include <fcntl.h>

// # define FILE_EXT	".fdf"

// # define WIN_WIDTH	1080
// # define WIN_HEIGHT	720

// # define ISO_ANGLE	120
// # define ROTT_ANGLE	0.1
// # define OFFSET_X	WIN_WIDTH / 3
// # define OFFSET_Y	WIN_HEIGHT / 3

// # define SCALE		15
// # define ZOOM_MAX	300
// # define ZOOM_MIN	1
// # define ZOOM_SPEED	1
// # define ROTT_SPEED	5

// # define KEY_PLUS	69
// # define KEY_MINUS	78
// # define KEY_ESCAPE	53
// # define KEY_SPACE	49
// # define KEY_UP		126
// # define KEY_DOWN	125
// # define KEY_LEFT	123
// # define KEY_RIGHT	124

// # define MOUSE_UP	4
// # define MOUSE_DOWN	5

// # define ERR_MSG_01	"ERROR: invalid argument count (Usage: ./fdf map.fdf).\n"
// # define ERR_MSG_02	"ERROR: invalid file extension (Usage: ./fdf map.fdf).\n"
// # define ERR_MSG_03	"ERROR: invalid file or file does not exist.\n"
// # define ERR_MSG_04	"ERROR: invalid map: empty lines are not allowed.\n"
// # define ERR_MSG_05	"ERROR: invalid map: map is empty.\n"
// # define ERR_MSG_06	"ERROR: invalid map: failed to parse map.\n"
// # define ERR_MSG_07	"ERROR: invalid map: failed to read map from file.\n"
// # define ERR_MSG_08	"ERROR: invalid map: all rows should have same size.\n"
// # define ERR_MSG_09	"ERROR: malloc() failed.\n"

// typedef struct s_img
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_img;

// typedef struct s_mlx
// {
// 	void	*mlx;
// 	void	*win;
// 	t_img	img;
// }				t_mlx;

// typedef struct s_row
// {
// 	int	*row;
// 	int	row_size;
// }				t_row;

// typedef struct s_map
// {
// 	t_row	*rows;
// 	int		row_count;
// 	int		scale;
// 	int		angle;
// }				t_map;

// typedef struct s_fdf
// {
// 	t_mlx	mlx;
// 	t_map	map;
// 	int		error;
// }				t_fdf;

// int		do_fdf(t_fdf *fdf, char *path);
// int		parse_arg(t_fdf *fdf, char *arg);
// void	print_error(int error_code);
// void	clean_rows(t_row *rows, int size);
// void	convert_3D_to_2D(int x, int y, int z, int *screen_x, int *screen_y, int scale, int angle);

#endif