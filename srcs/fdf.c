/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:08:42 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/04 17:39:27 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static void	do_fdf(t_fdf *f)
{
	define_map_constants(f);
	define_offset(f);
	apply_gradient(f);
	apply_projection(f);
	apply_offset(f);
	draw_fdf(f);
	mlx_key_hook(f->mlx.win, handle_event, f);
	mlx_loop(f->mlx.mlx);
}

void	fdf(int ac, char **av)
{
	t_fdf	f;
	int		error_code;

	pre_init_data(&f);
	error_code = validate_arg(ac, av);
	if (0 == error_code)
		error_code = init_data(&f, av[0]);
	if (0 == error_code)
		error_code = parse_arg(&f, av[0]);
	if (0 == error_code)
		error_code = validate_data(&f);
	if (0 == error_code)
		do_fdf(&f);
	print_error(error_code);
	clean_data(&f);
}
