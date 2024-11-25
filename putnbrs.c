/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:04:06 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/25 20:33:44 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned_nbr(unsigned long n, int *len)
{
	unsigned int	nb;
	unsigned int	nbr;

	nbr = (unsigned int)n;
	nb = n;
	if (nbr > 9)
	{
		ft_put_unsigned_nbr(nbr / 10, len);
		ft_put_unsigned_nbr(nbr % 10, len);
	}
	if (nbr <= 9)
	{
		ft_putchar(nbr + 48, len);
	}
}

void	ft_putnbr(unsigned long n, int *len)
{
	int	nb;

	nb = (int)n;
	if (nb == -2147483648)
	{
		*len += write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', len);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	if (nb <= 9)
	{
		ft_putchar(nb + 48, len);
	}
}

void	ft_put_lowhexa_nbr(unsigned long n, int *len)
{
	char			*base;
	unsigned int	nbr;

	base = "0123456789abcdef";
	nbr = (unsigned int)n;
	if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr = -nbr;
	}
	if (nbr > 15)
	{
		ft_put_lowhexa_nbr(nbr / 16, len);
		ft_put_lowhexa_nbr(nbr % 16, len);
	}
	if (nbr <= 15)
	{
		ft_putchar(base[nbr], len);
	}
}

void	ft_put_upphexa_nbr(unsigned long n, int *len)
{
	char			*base;
	unsigned int	nbr;

	base = "0123456789ABCDEF";
	nbr = (unsigned int)n;
	if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr = -nbr;
	}
	if (nbr > 15)
	{
		ft_put_upphexa_nbr(nbr / 16, len);
		ft_put_upphexa_nbr(nbr % 16, len);
	}
	if (nbr <= 15)
	{
		ft_putchar(base[nbr], len);
	}
}
