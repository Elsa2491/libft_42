/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:03:01 by eltouma           #+#    #+#             */
/*   Updated: 2023/05/22 20:35:44 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	if (!s || s[0] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			result += 1;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i += 1;
	}
	return (result);
}

static int	ft_count_size_of_word(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i += 1;
	return (i);
}

static void	*free_strs(char **strs, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(strs[j]);
		j += 1;
	}
	free(strs);
	return (NULL);
}

static char	*ft_fill_strs(char const *s, char c)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_count_size_of_word(s, c);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		str[i] = s[i];
		i += 1;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**strs;

	j = 0;
	if (!s)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!strs)
		return (NULL);
	strs[ft_count_words(s, c)] = NULL;
	while (*s != '\0')
	{
		if (*s != c)
		{
			strs[j] = ft_fill_strs(s, c);
			if (!strs[j++])
				return (free_strs(strs, j));
			while (*s != '\0' && *s != c)
				s += 1;
		}
		else
			s += 1;
	}
	return (strs);
}
