/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:51:01 by najgharb          #+#    #+#             */
/*   Updated: 2025/06/02 19:02:34 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(char *s)
{
	double	res;
	double	fraction;
	char	sign;

	sign = 0;
	res = 0.0;
	fraction = 1.0;
	if ((*s == '-' && --sign) || *s == '+')
		s++;
	while (ft_isdigit(*s))
	{
		res = (res * 10) + (*s - 48);
		s++;
	}
	s++;
	while (ft_isdigit(*s))
	{
		fraction /= 10.0;
		res += (*s - 48) * fraction;
		s++;
	}
	if (sign)
		return (res * -1);
	return (res);
}
