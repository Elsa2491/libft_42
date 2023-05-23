/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:42:16 by eltouma           #+#    #+#             */
/*   Updated: 2023/05/22 16:16:06 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			s_size;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	s_size = ft_strlen(s);
	if (start >= s_size)
		len = 0;
	if (len > s_size - start)
		len = s_size - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		start += 1;
		i += 1;
	}
	str[i] = '\0';
	return (str);
}
