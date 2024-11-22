/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:29:02 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/22 01:54:18 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

format_t	*init_format_array(int *i, int *len)
{
	*i = 0;
    *len = 0; 
    static format_t	arr[3] = {{'c', ft_putchar}, {'s', ft_putstr}, {'%',
		print_mod}};

	return (arr);
}

int	ft_printf(const char *format, ...)
{
	var_t	var;

	va_start(var.arg, format);
    var.arr = init_format_array(&var.i, &var.len);
	while (format[var.i])
	{
		var.check = 0;
		if (format[var.i] == '%')
		{
			var.i++;
			var.j = 0;
			while (var.j++ < 4)
			{
				if (format[var.i] == var.arr[var.j].specifier)
				{
					var.check = 1;
					var.arr[var.j].function_pointer(var.arg, &var.len);
				}
			}
		}
		if (var.check == 0)
			write(1, &format[var.i], 1);
		var.i++;
	}
	return (var.len);
}

int	main(void)
{
	printf(NULL, "huhu");
}
