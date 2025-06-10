/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:29:52 by najgharb          #+#    #+#             */
/*   Updated: 2024/02/02 12:30:05 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * 
 * 
 */

char	*ft_strrchr(const char *string, int c)
{
	int		contador;
	char	*ptr;

	contador = 0;
	ptr = NULL;
	while (string[contador] != '\0')
	{
		if (string[contador] == (unsigned char)c)
			ptr = (char *) &string[contador];
		contador++;
	}
	if (string[contador] == (unsigned char)c)
		ptr = (char *) &string[contador];
	return (ptr);
}

/* int main()
{
	char string[] = "";
	char c = 'o';
	char *ptr;

	ptr = ft_strrchr(string, c);
	if (ptr != NULL)
	{
		printf("Last occurrence of '%c' in '%s' is at 
		position: %ld\n", c, string, ptr - string);
	}
	else
	{
		printf("Character '%c' not found in '%s'\n", c, string);
	}

	return 0;
} */