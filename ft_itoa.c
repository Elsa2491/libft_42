/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:47:54 by eltouma           #+#    #+#             */
/*   Updated: 2023/05/16 19:41:26 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_digit(int n)
{
	int	result;

	result = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		result = 1;
	while (n != 0)
	{
		n /= 10;
		result += 1;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*str;

	nb = n;
	i = ft_count_digit(nb);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n < 0)
		nb *= -1;
	while (i > 0)
	{
		str[i - 1] = nb % 10 + 48;
		nb /= 10;
		i -= 1;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
