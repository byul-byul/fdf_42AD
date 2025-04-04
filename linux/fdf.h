/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:50:30 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/04 23:33:12 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <string.h>

//# include <unistd.h>
//# include <stdlib.h>
//# include <stdio.h>
//# include <errno.h>

# define TRUE					1
# define FALSE					0
# define ERR_MSG_ENABLED		TRUE

# define WIN_WIDTH				1600
# define WIN_HEIGHT				1200
# define WIN_NAME				"FDF"

# define DEFAULT_ANGLE			0.5
# define DEFAULT_SCALE			20
# define DEFAULT_OFFSET			0

# define ZOOM_STEP				1
# define ROTATE_STEP			0.01
# define TRANSLATION_STEP		10
# define STRAIGHTFORWARD_STEP	1

# define POSITIVE_ROTATION		1
# define NEGATIVE_ROTATION		0

# define CONIC_FACTOR_01		0.1
# define CONIC_FACTOR_02		1.0
# define FOCAL_LEN				1400

# define FILE_EXT				".fdf"
# define HEX_PREFIX				"0x"
# define HEX_BASE				"0123456789ABCDEF"
# define DEFAULT_COLOR			0
# define COLOR_MASK				0xFF
# define COLOR_MIN				0x0000FF
# define COLOR_MAX				0xFF0000

# define ESC_BUTTON_CODE		65307
# define PROJ_BUTTON_CODE		112
# define RESET_BUTTON_CODE		114
# define UP_BUTTON_CODE			65362
# define RIGHT_BUTTON_CODE		65363
# define DOWN_BUTTON_CODE		65364
# define LEFT_BUTTON_CODE		65361
# define W_BUTTON_CODE			119
# define D_BUTTON_CODE			100
# define S_BUTTON_CODE			115
# define A_BUTTON_CODE			97
# define Q_BUTTON_CODE			113
# define E_BUTTON_CODE			101
# define H_BUTTON_CODE			104
# define L_BUTTON_CODE			108
# define COMMA_BUTTON_CODE		44
# define DOT_BUTTON_CODE		46
# define PLUS_BUTTON_CODE		65451
# define MINUS_BUTTON_CODE		65453

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
	t_cell	**cells;
}				t_map;

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

int		handle_event(int keycode, t_fdf *f);
void	handle_escape_event(t_fdf *f);
void	handle_projection_event(t_fdf *f);
void	handle_reset_event(t_fdf *f);
void	handle_zoom_event(t_fdf *f, int keycode);
void	handle_translation_event(t_fdf *f, int keycode);
void	handle_rotation_event(t_fdf *f, int keycode);
void	handle_straightforward_event(t_fdf *f, int keycode);

void	apply_gradient(t_fdf *f);
void	apply_offset(t_fdf *f);
void	apply_zoom(t_fdf *f, int keycode);
void	apply_translation(t_fdf *f, int keycode);
void	apply_rotation(t_fdf *f, int keycode);
void	apply_projection(t_fdf *f);
void	apply_reset(t_fdf *f);
void	apply_straightforward(t_fdf *f, int keycode);

void	parallel_projection(t_fdf *f);
void	isometric_projection(t_fdf *f);
void	conic_projection(t_fdf *f);
void	perspective_projection(t_fdf *f);

void	rotate_x(t_fdf *f, int type);
void	rotate_y(t_fdf *f, int type);
void	rotate_z(t_fdf *f, int type);

int		interpolate_color(double ratio);

void	draw_fdf(t_fdf *f);
void	pre_init_data(t_fdf *f);
void	define_map_constants(t_fdf *f);
void	define_offset(t_fdf *f);

#endif