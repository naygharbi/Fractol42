/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:11:21 by najgharb          #+#    #+#             */
/*   Updated: 2024/01/30 11:56:41 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//strdup, strdup -- save a copy of a string

#include "libft.h"
/**
 * copiar una cadena de caracteres a un str[malloc]
 * 
 * la candena de caracteres que recibimos
 * char* la cadena de caractares almacenada en malloc
 */

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(ft_strlen(s1) + 1);
	if (!new)
		return (0);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
//antes de asignar el malloc 
	//hay que calcular la lengitude de la cadena principal s
		// copia la cadena s en la cadena nueva new
	// libero la nuva cadena con free
	//free(new); // estoy sacando mi espacio de la memoria con el free
	// devuelvo la nueva cad