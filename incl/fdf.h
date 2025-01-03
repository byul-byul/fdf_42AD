/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:50:30 by bhajili           #+#    #+#             */
/*   Updated: 2025/01/03 20:48:33 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <math.h>
# include <fcntl.h>

# define FILE_EXT	".fdf"

# define WIN_WIDTH	1080
# define WIN_HEIGHT	720

# define ISO_ANGLE	120
# define OFFSET_X	400
# define OFFSET_Y	200

# define SCALE		15
# define ZOOM_MAX	300
# define ZOOM_MIN	1
# define ZOOM_SPEED	1

# define KEY_PLUS	69
# define KEY_MINUS	78
# define KEY_ESCAPE	53
# define KEY_SPACE	49

# define ERR_MSG_01	"ERROR: invalid argument count (Usage: ./fdf map.fdf).\n"
# define ERR_MSG_02	"ERROR: invalid file extension (Usage: ./fdf map.fdf).\n"
# define ERR_MSG_03	"ERROR: invalid file or file does not exist.\n"
# define ERR_MSG_04	"ERROR: invalid map: empty lines are not allowed.\n"
# define ERR_MSG_05	"ERROR: invalid map: map is empty.\n"
# define ERR_MSG_06	"ERROR: invalid map: failed to parse map.\n"
# define ERR_MSG_07	"ERROR: invalid map: failed to read map from file.\n"
# define ERR_MSG_08	"ERROR: invalid map: all rows should have same size.\n"
# define ERR_MSG_09	"ERROR: malloc() failed.\n"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_mlx;

typedef struct s_row
{
	int	*row;
	int	row_size;
}				t_row;

typedef struct s_map
{
	t_row	*rows;
	int		row_count;
	int		scale;
}				t_map;

typedef struct s_fdf
{
	t_mlx	mlx;
	t_map	map;
	int		error;
}				t_fdf;

int		do_fdf(t_fdf *fdf, char *path);
int		parse_arg(t_fdf *fdf, char *arg);
void	print_error(int error_code);
void	clean_rows(t_row *rows, int size);
void	convert_3D_to_2D(int x, int y, int z, int *screen_x, int *screen_y, int scale);

#endif