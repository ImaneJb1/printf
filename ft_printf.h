/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:36:43 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/24 15:38:35 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_format
{
	char	specifier;
	void	(*function_pointer)(unsigned long, int *);
}			t_format;

void		ft_printchar(unsigned long arg, int *len);
void		ft_putstr(unsigned long arg, int *len);
void		print_mod(unsigned long arg, int *len);
void		ft_putnbr(unsigned long arg, int *len);
void		ft_putchar(char c, int *len);
void		ft_put_unsigned_nbr(unsigned long n, int *len);
void		ft_put_lowhexa_nbr(unsigned long n, int *len);
void		ft_put_upphexa_nbr(unsigned long n, int *len);
void		ft_putaddress(unsigned long n, int *len);

#endif