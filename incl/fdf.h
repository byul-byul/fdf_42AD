/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:50:30 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/31 20:07:32 by bhajili          ###   ########.fr       */
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

# define ERR_MSG_01	"ERROR: invalid argument count (Usage: ./fdf map.fdf).\n"
# define ERR_MSG_02	"ERROR: invalid file extension (Usage: ./fdf map.fdf).\n"
# define ERR_MSG_03	"ERROR: invalid file or file does not exist.\n"
# define ERR_MSG_04	"ERROR: invalid map: empty lines are not allowed.\n"
# define ERR_MSG_05	"ERROR: invalid map: failed to parse map.\n"
# define ERR_MSG_06	"ERROR: invalid map: failed to read map from file.\n"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		**map;
}				t_img;

typedef struct s_row
{
	int	*row;
	int	row_size;
}				t_row;

typedef struct s_map
{
	t_row	*rows;
	int		row_count;	
}				t_map;

typedef struct s_fdf
{
	t_img	img;
	t_map	map;
	int		error;
}				t_fdf;

int		parse_arg(t_fdf *fdf, char *arg);
void	print_error(int error_code);
void	free_int_arr(t_row **arr, int size);

#endif