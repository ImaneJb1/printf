/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:29:02 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/22 00:53:43 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format_array(format_t *arr, int *i, int *len)
{
	format_t	arr[3];

	*len = 0;
	*i = 0;
	arr[0].specifier = 'c';
	arr[0].function_pointer = ft_putchar;
	arr[1].specifier = 's';
	arr[1].function_pointer = ft_putstr;
	arr[2].specifier = '%';
	arr[2].function_pointer = print_mod;
}

int	ft_printf(const char *format, ...)
{
	var_t	var;

	init_format_array(var.arr, &var.i, &var.len);
	while (format[var.i])
	{
		var.check = 0;
		if (format[var.i] == '%')
		{
			var.i++;
			var.j = 0;
			while (var.j < sizeof(var.arr) / sizeof(var.arr[0]))
			{
				if (format[var.i] == var.arr[var.j].specifier)
				{
					var.check = 1;
					var.arr[var.j].function_pointer(var.arg, &var.len);
				}
				var.j++;
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
	ft_printf("imane\n %c", '6');
}
