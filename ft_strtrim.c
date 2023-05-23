/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:14:11 by eltouma           #+#    #+#             */
/*   Updated: 2023/05/22 20:41:17 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_is_char(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i += 1;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_is_char(s1[i], set))
		i += 1;
	j = ft_strlen(s1) - 1;
	while (j > i && ft_is_char(s1[j], set))
		j -= 1;
	str = (char *)malloc(sizeof(char) * j - i + 2);
	if (!str)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		str[k] = s1[i];
		i += 1;
		k += 1;
	}
	str[k] = '\0';
	return (str);
}
