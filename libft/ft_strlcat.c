/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:40:54 by najgharb          #+#    #+#             */
/*   Updated: 2024/01/22 19:08:21 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[i] != '\0' && dst_len + 1 < dstsize)
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (dst_len + src_len - i);
}

/* int main(void)
{
	char dst[50] = "pqrs";
	const char *src = "abcdefghi";
	//size_t dstsize = sizeof(dst);
	
	size_t result = ft_strlcat(dst, src, 10);
	
	printf("resultado: %zu\n", result);
	printf("cadena resultante: %s\n", dst);
	
	return (0);
} */