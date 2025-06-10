/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:45:33 by najlghar          #+#    #+#             */
/*   Updated: 2025/06/10 16:51:03 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42_Int.h"

# ifndef MAX_ITER
#  define MAX_ITER 255
# endif

typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;

typedef struct s_fractol
{
	char		*name;
	double		x;
	double		y;
	int			color;
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		mag;
	double		xmag;
	int			height;
	int			width;
	double		px_rate;
	double		r;
	double		i;
	double		xd;
	double		yd;
}	t_data;

int		args_checker(int ac, char **argv);
void	calc_coordinates(t_data *info);
double	ft_atod(char *s);

#endif