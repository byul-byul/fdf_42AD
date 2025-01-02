/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:49:39 by bhajili           #+#    #+#             */
/*   Updated: 2025/01/02 11:30:19 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static int	do_fdf(t_fdf *fdf, char *path)
{
	int	i;
	int	j;

	path += 0;
	fdf += 0;
	i = -1;
	while (++i < fdf->map.row_count)
	{
		j = -1;
		while (++j < fdf->map.rows[i].row_size)
			ft_printf("%d, ", fdf->map.rows[i].row[j]);
		ft_printf("\n");
	}
	ft_printf("do_fdf() execution.\n");
	return (1);
}

static int	check_row_sizes(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (++i < fdf->map.row_count)
		if (fdf->map.rows[0].row_size != fdf->map.rows[i].row_size)
			return (clean_rows(fdf->map.rows, fdf->map.row_count), \
					fdf->error = 8, 0);
	return (1);
}

static int	is_valid_arg(t_fdf *fdf, int ac, char **av)
{
	if (ac != 2)
		return (fdf->error = 1, 0);
	if (ft_strlen(ft_strstr(av[1], FILE_EXT)) != ft_strlen(FILE_EXT))
		return (fdf->error = 2, 0);
	return (1);
}

static void	fdf(int ac, char **av)
{
	t_fdf	fdf;

	if (is_valid_arg(&fdf, ac, av))
		if (parse_arg(&fdf, av[1]))
			if (check_row_sizes(&fdf))
				if (do_fdf(&fdf, av[1]))
					return ;
	print_error(fdf.error);
}

int	main(int ac, char **av)
{
	fdf(ac, av);
	return (0);
}
