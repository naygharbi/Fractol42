/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:47:22 by najgharb          #+#    #+#             */
/*   Updated: 2024/01/18 10:54:23 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*destiny;
	const char	*source;

	i = 0;
	destiny = dst;
	source = src;
	while (i < n && (src != NULL || dst != NULL))
	{
		destiny[i] = source[i];
		i++;
	}
	return (dst);
}
