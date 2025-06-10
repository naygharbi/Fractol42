/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:29:01 by najgharb          #+#    #+#             */
/*   Updated: 2023/12/28 18:26:50 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - void* no es una variable --> apunta una cadena
// cc es un compilador y ./a.out es un archivo 
#include "libft.h"

int	ft_isprint(int numero)
{
	if (numero >= 32 && numero <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

//int	main(void)
//{
//	int	a;
//	a = ft_isprint('s');
//	printf("%i", a);
//}
