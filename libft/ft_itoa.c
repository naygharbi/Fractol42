/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:26:10 by najgharb          #+#    #+#             */
/*   Updated: 2024/02/02 12:09:34 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	function1(int n)
{
	int	i;

	i = 0;
	if (!n)
		return (-1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	function2(long j, char *ptr, int i)
{
	int	rest;

	while (j)
	{
		rest = j % 10;
		j = j / 10;
		ptr[i] = rest + '0';
		i--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	long	j;
	char	*ptr;

	j = n;
	i = function1(n);
	if (i < 0)
		return (ft_strdup("0"));
	ptr = (char *)malloc(i + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[i--] = 0;
	if (j < 0)
	{
		ptr[0] = '-';
		j = -j;
	}
	function2(j, ptr, i);
	return (ptr);
}
