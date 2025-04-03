/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:58:24 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 15:27:56 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
//#define SCALE_ROTATE 1000  // Чем больше, тем выше точность

//void rotate_x(int *y, int *z, int angle, int center_y, int center_z)
//{
//    double rad = angle * M_PI / 180.0;
//    double rad_cos = cos(rad);
//    double rad_sin = sin(rad);

//    double tmp_y = *y - center_y;
//    double tmp_z = *z - center_z;

//    *y = (int)round(tmp_y * rad_cos - tmp_z * rad_sin) + center_y;
//    *z = (int)round(tmp_y * rad_sin + tmp_z * rad_cos) + center_z;
//}

//void rotate_y(int *x, int *z, int angle, int center_x, int center_z)
//{
//    double rad = angle * M_PI / 180.0;
//    double rad_cos = cos(rad);
//    double rad_sin = sin(rad);

//    double tmp_x = *x - center_x;
//    double tmp_z = *z - center_z;

//    *x = (int)round(tmp_x * rad_cos + tmp_z * rad_sin) + center_x;
//    *z = (int)round(-tmp_x * rad_sin + tmp_z * rad_cos) + center_z;
//}

//void rotate_z(int *x, int *y, int angle, int center_x, int center_y)
//{
//    double rad = angle * M_PI / 180.0;
//    double rad_cos = cos(rad);
//    double rad_sin = sin(rad);

//    double tmp_x = *x - center_x;
//    double tmp_y = *y - center_y;

//    *x = (int)round(tmp_x * rad_cos - tmp_y * rad_sin) + center_x;
//    *y = (int)round(tmp_x * rad_sin + tmp_y * rad_cos) + center_y;
//}

//void find_map_center(t_fdf *f, int *center_x, int *center_y, int *center_z) {
//    int min_x = INT_MAX, max_x = INT_MIN;
//    int min_y = INT_MAX, max_y = INT_MIN;
//    int min_z = INT_MAX, max_z = INT_MIN;

//    for (int y = 0; y < f->map->height; y++) {
//        for (int x = 0; x < f->map->width; x++) {
//            t_cell *cell = &f->map->cells[y][x];
//            if (cell->x < min_x) min_x = cell->x;
//            if (cell->x > max_x) max_x = cell->x;
//            if (cell->y < min_y) min_y = cell->y;
//            if (cell->y > max_y) max_y = cell->y;
//            if (cell->z < min_z) min_z = cell->z;
//            if (cell->z > max_z) max_z = cell->z;
//        }
//    }

//    *center_x = (min_x + max_x) / 2;
//    *center_y = (min_y + max_y) / 2;
//    *center_z = (min_z + max_z) / 2;
//}

//void apply_rotation(t_fdf *f, int keycode) {
//    int x, y;
//    int center_x, center_y, center_z;

//    find_map_center(f, &center_x, &center_y, &center_z);
//    // refresh_cells(f);

//    for (y = 0; y < f->map->height; y++) {
//        for (x = 0; x < f->map->width; x++) {
//            t_cell *cell = &f->map->cells[y][x];

//            if (keycode == UP_BUTTON_CODE)
//                rotate_x(&cell->y, &cell->z, ROT_ANGLE, center_y, center_z);
//            else if (keycode == DOWN_BUTTON_CODE)
//                rotate_x(&cell->y, &cell->z, -ROT_ANGLE, center_y, center_z);
//            else if (keycode == RIGHT_BUTTON_CODE)
//                rotate_y(&cell->x, &cell->z, ROT_ANGLE, center_x, center_z);
//            else if (keycode == LEFT_BUTTON_CODE)
//                rotate_y(&cell->x, &cell->z, -ROT_ANGLE, center_x, center_z);
//            else if (keycode == COMMA_BUTTON_CODE)
//                rotate_z(&cell->x, &cell->y, ROT_ANGLE, center_x, center_y);
//            else if (keycode == DOT_BUTTON_CODE)
//                rotate_z(&cell->x, &cell->y, -ROT_ANGLE, center_x, center_y);
//        }
//    }
//}

static void	rotate_x(t_fdf *f, int type)
{
	if (type)
		f->map->angle_x += ROTATE_STEP;
	else
		f->map->angle_x -= ROTATE_STEP;
	apply_projection(f);
}

static void	rotate_y(t_fdf *f, int type)
{
	if (type)
		f->map->angle_y += ROTATE_STEP;
	else
		f->map->angle_y -= ROTATE_STEP;
	apply_projection(f);
}

static void	rotate_z(t_fdf *f, int type)
{
	if (type)
		f->map->angle_z += ROTATE_STEP;
	else
		f->map->angle_z -= ROTATE_STEP;
	apply_projection(f);
}

void	apply_rotation(t_fdf *f, int keycode)
{
	if (keycode == W_BUTTON_CODE)
		rotate_x(f, POSITIVE_ROTATION);
	else if (keycode == S_BUTTON_CODE)
		rotate_x(f, NEGATIVE_ROTATION);
	else if (keycode == D_BUTTON_CODE)
		rotate_y(f, POSITIVE_ROTATION);
	else if (keycode == A_BUTTON_CODE)
		rotate_y(f, NEGATIVE_ROTATION);
	else if (keycode == Q_BUTTON_CODE)
		rotate_z(f, POSITIVE_ROTATION);
	else if (keycode == E_BUTTON_CODE)
		rotate_z(f, NEGATIVE_ROTATION);
}
