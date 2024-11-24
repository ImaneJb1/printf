/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:29:02 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/23 15:36:06 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*init_func(void)
{
	static t_format	arr[] = {{'c', ft_putchar}, {'s', ft_putstr}, {'%',
			print_mod}, {'d', ft_putnbr}, {'i', ft_putnbr}};

	return (arr);
}

void	specifier_handler(t_format *arr, const char *character, va_list arg,
		int *len)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (*character == arr[j].specifier)
		{
			arr[j].function_pointer(va_arg(arg, unsigned long), len);
			return;
		}
		j++;
	}
}

int	ft_printf(const char *format, ...)
{
	t_format	*arr;
	va_list		arg;
	int			len;
	int			i;

	arr = init_func();
	va_start(arg, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			specifier_handler(arr, &format[i], arg, &len);
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	return (len);
}

int	main(void)
{
	printf("Got:\n");
	ft_printf("imane %d %s %%\n", -5, "100");
	// printf("Expected: \n");
	// printf("imane %d %s %%\n", 5, "jb");
}
