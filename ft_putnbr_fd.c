/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:11:49 by eltouma           #+#    #+#             */
/*   Updated: 2023/05/12 15:23:13 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_int_to_ascii(int n, int fd)
{
	char	c;

	c = n + '0';
	ft_putchar_fd(c, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb <= 9)
		ft_int_to_ascii(nb, fd);
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_int_to_ascii(nb % 10, fd);
	}
}
