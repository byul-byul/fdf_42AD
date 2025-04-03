/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:50:30 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 15:38:19 by bhajili          ###   ########.fr       */
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

# define TRUE					1
# define FALSE					0
# define ERR_MSG_ENABLED		TRUE

# define WIN_WIDTH				1600
# define WIN_HEIGHT				1200
# define WIN_NAME				"FDF"

# define DEFAULT_ANGLE			0.5
# define DEFAULT_SCALE			20
# define ZOOM_STEP				1
# define ROTATE_STEP			0.01
# define POSITIVE_ROTATION		1
# define NEGATIVE_ROTATION		0
//# define ISO_ANGLE_X			0.5
//# define ISO_ANGLE_Y			0.5
# define ROT_ANGLE				2
# define OFFSET_X				WIN_HEIGHT / 3
# define OFFSET_Y				WIN_HEIGHT / 3
# define OFFSET_Z				WIN_HEIGHT / 3
//# define SCALE					20
//# define SCALE_Z				42
# define CONIC_FACTOR			0.1
# define CAVALIER_FACTOR		0.5
# define CABINET_FACTOR			0.25
# define FOCAL_LENGTH			800

# define FILE_EXT				".fdf"
# define HEX_PREFIX				"0x"
# define HEX_BASE				"0123456789ABCDEF"
# define DEFAULT_COLOR			0
# define COLOR_MASK				0xFF
# define COLOR_MIN				0x0000FF
# define COLOR_MAX				0xFF0000

# define ESC_BUTTON_CODE		53
# define PROJ_BUTTON_CODE		35
# define UP_BUTTON_CODE			126
# define RIGHT_BUTTON_CODE		124
# define DOWN_BUTTON_CODE		125
# define LEFT_BUTTON_CODE		123
# define W_BUTTON_CODE			13
# define D_BUTTON_CODE			2
# define S_BUTTON_CODE			1
# define A_BUTTON_CODE			0
# define Q_BUTTON_CODE			12
# define E_BUTTON_CODE			14
# define COMMA_BUTTON_CODE		43
# define DOT_BUTTON_CODE		47
# define PLUS_BUTTON_CODE		69
# define MINUS_BUTTON_CODE		78

# define ERR_MSG_00	"Error\n"
# define ERR_MSG_01	"invalid argument count (Usage: ./fdf map.fdf).\n"
# define ERR_MSG_02	"invalid file extension (Usage: ./fdf map.fdf).\n"
# define ERR_MSG_03	"malloc() failed.\n"
# define ERR_MSG_04	"open() failed.\n"
# define ERR_MSG_05	"invalid map height.\n"
# define ERR_MSG_06	"invalid map: empty lines found.\n"
# define ERR_MSG_07	"invalid map: different row size.\n"
# define ERR_MSG_08	"invalid map width.\n"
# define ERR_MSG_09	"get_next_line() failed.\n"
# define ERR_MSG_10	"mlx_init() failed.\n"
# define ERR_MSG_11	"mlx_new_window() failed.\n"
# define ERR_MSG_12	"mlx_new_image() failed.\n"
# define ERR_MSG_13	"mlx_get_data_addr() failed.\n"

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}				t_line;

typedef struct s_cell
{
	int	x;
	int	y;
	int	z;
	int	original_x;
	int	original_y;
	int	original_z;
	int	color;
}				t_cell;

typedef struct s_map
{
	int		scale;
	int		width;
	int		height;
	int		max_z;
	int		max_y;
	int		max_x;
	int		min_z;
	int		min_y;
	int		min_x;
	int		center_z;
	int		center_y;
	int		center_x;
	int		offset_z;
	int		offset_y;
	int		offset_x;
	double	angle_z;
	double	angle_y;
	double	angle_x;
	char	*file_path;
	t_cell	**cells;
}				t_map;

//typedef struct s_camera
//{
//	double	zoom;
//	double	angle_x;
//	double	angle_y;
//	double	angle_z;
//	int		offset_x;
//	int		offset_y;
//	double	height_mod;
//}				t_camera;

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

typedef enum e_error_code
{
	ERR_CODE_ARG_COUNT,
	ERR_CODE_INVALID_FILE,
	ERR_CODE_MEMORY_FAIL,
	ERR_CODE_OPEN_FAIL,
	ERR_CODE_INVALID_MAP_H,
	ERR_CODE_INVALID_MAP_E,
	ERR_CODE_INVALID_MAP_R,
	ERR_CODE_INVALID_MAP_W,
	ERR_CODE_GNL,
	ERR_CODE_MLX_INIT,
	ERR_CODE_MLX_WIN,
	ERR_CODE_MLX_IMG,
	ERR_CODE_MLX_ADDR
}			t_error_code;

typedef enum e_proj_type
{
	ISOMETRIC,
	PARALLEL,
	CONIC,
	CAVALIER,
	CABINET,
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
	int				allocated_cellrow_count;
	t_map			*map;
	//t_camera		camera;
	t_projection	projection;
	t_mlx			mlx;
}				t_fdf;

void	fdf(int ac, char **av);
int		validate_arg(int ac, char **av);
int		init_data(t_fdf *f, char *path);
int		validate_data(t_fdf *f);
int		parse_arg(t_fdf *f, char *path);
void	clean_data(t_fdf *f);
int		get_file_line_count(char *path);
int		get_column_count(char *row);
void	print_error(int error_code);
void	clean_cells(t_cell **cells, int count);
void	apply_projection(t_fdf *f);
void	define_map_min_max(t_fdf *f);
void	apply_gradient(t_fdf *f);
int		handle_event(int keycode, t_fdf *f);
void	draw_fdf(t_fdf *f);
void	refresh_cells(t_fdf *f);
void	apply_rotation(t_fdf *f, int keycode);
//void	draw_line(t_fdf *f, t_cell a, t_cell b);
void	pre_init_data(t_fdf *f);
//void	refresh_image(t_fdf *f);
void	define_map_center(t_fdf *f);
void	define_offset(t_fdf *f);
//void	apply_scale(t_fdf *f);

#endif