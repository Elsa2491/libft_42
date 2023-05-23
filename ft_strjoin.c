/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:28:11 by eltouma           #+#    #+#             */
/*   Updated: 2023/05/22 20:43:42 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_malloc(char const *s1, char const *s2)
{
	int		size;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * size + 1);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	str = ft_malloc(s1, s2);
	i = 0;
	if (str == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i += 1;
	}
	str[i] = '\0';
	j = ft_strlen(str);
	i = 0;
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
		j += 1;
		i += 1;
	}
	str[j] = '\0';
	return (str);
}
