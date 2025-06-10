/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:42:06 by najgharb          #+#    #+#             */
/*   Updated: 2024/01/18 10:37:32 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_c;

	i = 0;
	ptr_c = (unsigned char *)s;
	while (i < n)
	{
		if (ptr_c[i] == (unsigned char)c)
		{
			ptr_c = (void *)&ptr_c[i];
			return (ptr_c);
		}
		i++;
	}
	ptr_c = NULL;
	return ((void *)ptr_c);
}
