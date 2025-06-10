/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:35:44 by najgharb          #+#    #+#             */
/*   Updated: 2024/02/02 12:28:21 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * buscar el caracter dentro de la cadena
 * 
 */

char	*ft_strchr(const char *string, int c)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (unsigned char)c)
			return ((char *)(string + i));
		i++;
	}
	if (string[i] == (unsigned char)c)
		return ((char *)(string + i));
	return (NULL);
}
