/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:20:22 by najgharb          #+#    #+#             */
/*   Updated: 2024/01/29 12:49:56 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// char *func [a -> o]
// char str [hala] -> char new_str [holo]
// char *func [a -> aaa]
// char str [hala] -> char new_str [haaalaaa]
// char *func [a -> 123]
// char str [hala] -> char new_str [h123l123]
// char *func [' ' -> ', ']
// char str [hello world] -> char new_str [hello, world]
// char *func [abc -> bcd]
// char str [] -> char new_str [hello, world]

#include "libft.h"
/* char f(unsigned int i, char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    return c;
} */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*c;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	c = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	if (!c)
		return (NULL);
	while (s[i] != '\0')
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}

/* int main() {
    char const *s = "hello";
    char *result = ft_strmapi(s, f);
    if (result) {
        printf("%s\n", result);
        free(result);
    }
    return 0;
} */