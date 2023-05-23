/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:55:43 by eltouma           #+#    #+#             */
/*   Updated: 2023/05/22 16:18:00 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (len == 0 && (big == NULL || little == NULL))
		return (NULL);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] == little[j] && (i + j) < len)
		{
			if (j + 1 == ft_strlen(little))
				return ((char *)&big[i]);
			j += 1;
		}
		i += 1;
	}
	return (NULL);
}
