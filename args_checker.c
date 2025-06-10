/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:11:33 by najgharb          #+#    #+#             */
/*   Updated: 2025/06/10 17:05:48 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_coordinate(char *x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (x[0] == '-' || x[0] == '+')
		i = 1;
	while (x[i] != '\0')
	{
		if (ft_isdigit(x[i]) == 0 && x[i] != '.')
			return (0);
		else if (x[i] == '.')
			j++;
		i++;
	}
	if (j > 1)
		return (0);
	return (1);
}

int	args_checker(int ac, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) != 0
		&& ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) != 0)
		ft_putstr_fd("fractol invalid\n", STDERR_FILENO);
	else if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) && ac > 2)
		ft_putstr_fd("The Mandelbrot set does not require parameters\n",
			STDERR_FILENO);
	else if (!ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) && ac < 4)
		ft_putstr_fd("The Julia set requires parameters x and y\n",
			STDERR_FILENO);
	else if (!ft_strncmp(argv[1], "julia", ft_strlen(argv[1]))
		&& (check_coordinate(argv[2]) == 0 || check_coordinate(argv[3]) == 0))
		ft_putstr_fd("The coordinates are not valid\n",
			STDERR_FILENO);
	else
		return (0);
	return (1);
}
