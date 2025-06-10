/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coordenates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:06:40 by najgharb          #+#    #+#             */
/*   Updated: 2025/06/10 16:59:45 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>
#define MAX_ITER 255
/**
 * @img: img struct;
 * xmag: width magnitude.
 * ypx_rate: height pixel rate.
 * @return: void.
 */

void	color_pixel(void *pixel, t_uchar i, t_uchar c)
{
	t_uchar	*pxl;
	t_uchar	iter;

	iter = 0;
	pxl = (t_uchar *)pixel;
	if (i == MAX_ITER)
		ft_memset(pxl, 0, 4);
	else
	{
		while (iter < 3)
		{
			if (iter == c)
				ft_memset(pxl + iter, 0x3c, 1);
			else
				ft_memset(pxl + iter, i * i + 115, 1);
			iter++;
		}
		ft_memset(pxl + 3, i * i + 5, 1);
	}
}

void	mandel_calc(void *inf, void *pixel, double r, double i)
{
	t_data	*info;
	t_uint	iter;
	double	x;
	double	y;
	double	xtmp;

	info = (t_data *)inf;
	iter = 0;
	xtmp = 0;
	x = 0;
	y = 0;
	while ((x * x) + (y * y) < (2 * 2) && iter < MAX_ITER)
	{
		xtmp = (x * x) - (y * y) + r;
		y = (2 * x * y) + i;
		x = xtmp;
		iter++;
	}
	color_pixel(pixel, iter, info->color);
}

void	julia_calc(void *info, void *pixel, double r, double i)
{
	t_data	*inf;
	t_uint	iter;
	double	xtmp;

	inf = (t_data *)info;
	iter = 0;
	xtmp = 0;
	while ((r * r) + (i * i) < (2 * 2) && iter < MAX_ITER)
	{
		xtmp = (r * r) - (i * i) + inf->x;
		i = (2 * r * i) + inf->y;
		r = xtmp;
		iter++;
	}
	color_pixel(pixel, iter, inf->color);
}

void	draw_fractal(t_data *inf, void (*f)(void *, void *, double, double))
{
	double	r;
	double	i;
	void	*pixel;
	t_uint	iterx;
	t_uint	itery;

	r = inf->r;
	i = inf->i;
	iterx = 0;
	itery = 1;
	pixel = inf->img->pixels;
	while (itery <= inf->img->height)
	{
		r = inf->r;
		iterx = (inf->img->width * itery) - inf->img->width;
		while (iterx < inf->img->width * itery)
		{
			(*f)(inf, pixel + (iterx * 4), r, i);
			iterx++;
			r += 1.0 / inf->px_rate;
		}
		itery++;
		i += 1.0 / inf->px_rate;
	}
}

void	calc_coordinates(t_data *info)
{
	info->px_rate = info->img->height / info->mag;
	info->i = (info->mag / 2.0) * -1;
	info->xmag = info->img->width / info->px_rate;
	info->r = (info->xmag / 2.0) * -1;
	if (info->name[0] == 'm')
		draw_fractal(info, &mandel_calc);
	else
		draw_fractal(info, &julia_calc);
}
