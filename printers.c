/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:12:14 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/25 20:06:45 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_printchar(unsigned long n, int *len)
{
	char	c;

	c = n;
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr(unsigned long n, int *len)
{
	int		i;
	char	*s;

	s = (char *)n;
	if (s == NULL)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	*len += i;
}

void	put_0x(unsigned long n, int *len)
{
	ft_putchar('0', len);
	ft_putchar('x', len);
	ft_putaddress(n, len);
}

void	ft_putaddress(unsigned long n, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
	}
	if (n > 15)
	{
		ft_putaddress(n / 16, len);
		ft_putaddress(n % 16, len);
	}
	if (n <= 15)
	{
		ft_putchar(base[n], len);
	}
}
