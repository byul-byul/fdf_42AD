/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializator_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:39:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/04 19:34:42 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	pre_init_data(t_fdf *f)
{
	f->has_allocated_map = 0;
	f->has_allocated_cells = 0;
	f->allocated_cellrow_count = 0;
	f->map = NULL;
	f->mlx.mlx = NULL;
	f->mlx.win = NULL;
	f->mlx.img = NULL;
}
