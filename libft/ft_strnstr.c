/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:52:59 by najgharb          #+#    #+#             */
/*   Updated: 2024/02/02 12:34:52 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len_s2;

	if (*s2 == '\0')
		return ((char *)s1);
	len_s2 = ft_strlen(s2);
	while (*s1 != '\0' && n-- >= len_s2)
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, len_s2) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*s1;
// 	const char	*s2;
// 	size_t		n;

// 	s1 = "Hola soy yo soy yo";
// 	s2 = "soy";
// 	n = 14;
// 	printf("%s\n", strnstr (s1, s2, n));
// 	return (0);
// }