/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:50:07 by najgharb          #+#    #+#             */
/*   Updated: 2024/02/02 12:33:08 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Se usa para llenar un bloque de memoria con un valor particular
// This function, ft_memset, will take a pointer to a block of memory,
// a value to fill that memory with, and the number of bytes to fill.
#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < len)
	{
		p[i] = (unsigned char)x;
		i++;
	}
	return (p);
}
/*
int	main(void) {
	char	str[] = "Hello World";
	char	*ptr;

	ptr = ft_memset(str, 'j', 5);
	printf("%s\n", ptr);  // Output: "jjjjj, World!"
	return (0);
}
*/