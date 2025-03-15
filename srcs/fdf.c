/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   fdf.c											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bhajili <bhajili@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/28 12:08:42 by bhajili		   #+#	#+#			 */
/*   Updated: 2025/01/03 19:42:45 by bhajili		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../incl/fdf.h"

static void	show_data(t_fdf f)
{
	int	y;
	int	x;

	y = -1;
	ft_printf("f.has_allocated_map = %d\n", f.has_allocated_map);
	ft_printf("f.has_allocated_cells = %d\n", f.has_allocated_cells);
	ft_printf("f.allocated_cell_count = %d\n", f.allocated_cell_count);
	ft_printf("f.map->file_path = %s\n", f.map->file_path);
	ft_printf("f.map->width = %d\n", f.map->width);
	ft_printf("f.map->height = %d\n", f.map->height);
	while (++y < f.map->height)
	{
		x = -1;
		while (++x < f.map->width)
			ft_printf("%d,%d,%d ", f.map->cells[y][x].x, f.map->cells[y][x].y, f.map->cells[y][x].z);
		ft_printf("\n");
	}
}

int	do_fdf(t_fdf *f)
{
	f += 0;
	return (0);
}

int	validate_data(t_fdf *f)
{
	f += 0;
	return (0);
}

void	fdf(int ac, char **av)
{
	t_fdf	f;
	int		error_code;

	error_code = validate_arg(ac, av);
	if (0 == error_code)
		error_code = init_data(&f, av[0]);
	if (0 == error_code)
		error_code = parse_arg(&f, av[0]);
	if (0 == error_code)
		error_code = validate_data(&f);
	if (0 == error_code)
		error_code = do_fdf(&f);
	print_error(error_code);
	show_data(f);
	clean_data(&f);
}
