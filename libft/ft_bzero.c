/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:53:24 by najgharb          #+#    #+#             */
/*   Updated: 2024/02/02 12:32:23 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i++] = 0;
	}
	return (p);
}
/*
int	main() {
	char	str[] = "Hello World";
	char	*ptr;
	int		i;

	ptr = ft_bzero(str, 5);
	i = 0;
	while (i < 10)
	{
		printf("%i\n", ptr[i++]);
	}
	return (0);
}
*/
/*
void	*ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return (s);
}
*/