/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:25:56 by najgharb          #+#    #+#             */
/*   Updated: 2025/06/02 18:25:56 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_data(t_data *data, char **argv, int argc)
{
	data->x = 0.0;
	data->y = 0.0;
	if (argc == 4)
	{
		data->x = ft_atod(argv[2]);
		data->y = ft_atod(argv[3]);
	}
	data->color = 0x0;
	data->width = 800;
	data->height = 600;
	data->mag = 4;
	data->px_rate =  data->mag / data->width;
	data->name = argv[1];
}

void	scroll_manager(double xd, double yd, void *params)
{
	t_data	*inf;

	inf = (t_data *)params;
	if (yd > 0 || xd > 0)
		inf->mag = inf->mag - (inf->mag * 0.05);
	else if (yd < 0 || xd < 0)
		inf->mag = inf->mag + (inf->mag * 0.05);
	calc_coordinates(inf);
}

void key_manager(mlx_key_data_t keydata, void* param)
{
	t_data	*window;

	window = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(window->mlx);
}

void	ft_display(t_data *data)
{
	data->mlx = mlx_init(data->width, data->height, "fractol42", true);
	if (data->mlx == NULL)
	{
		ft_putstr_fd("MLX FAILED", 2);
		return ;
	}
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	if (data->mlx == NULL)
	{
		ft_putstr_fd("MLX IMG FAILED", 2);
		return ;
	}
	calc_coordinates(data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_scroll_hook(data->mlx, &scroll_manager, data);
	mlx_key_hook(data->mlx, &key_manager, data);
	mlx_loop(data->mlx);
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || argc > 4)
	{
		ft_putstr_fd("Uso: ./fractol <mandelbrot | (julia x y)>\n", STDOUT_FILENO);
		return (1);
	}
	if (args_checker(argc, argv) == 1)
		return (1);
	ft_init_data(&data, argv, argc);
	ft_display(&data);
	mlx_delete_image(data.mlx, data.img)
	mlx_terminate(data.mlx);
	ft_memset(&data, 0, sizeof(t_data));
	return (0);
}