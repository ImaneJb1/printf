/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:29:02 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/24 23:26:41 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


t_format	*init_func(void)
{
	static t_format	arr[] = {{'c', ft_printchar}, {'s', ft_putstr}, {'%',
			print_mod}, {'d', ft_putnbr}, {'i', ft_putnbr}, {'u', 
			ft_put_unsigned_nbr}, {'x', ft_put_lowhexa_nbr}, {'X', ft_put_upphexa_nbr}, {'p', ft_putaddress}};

	return (arr);
}

void	specifier_handler(t_format *arr, const char *character, va_list arg,
		int *len)
{
	int	j;

	j = 0;
	while (j < 9)
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
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(arg);
	return (len);
}

// int	main(void)
// {
// 	// printf("Got:\n");
// 	char c = 'c';
// 	 int a = printf("ori %c\n", 'h');
// 	int b = ft_printf("ana %c\n", 'h');
// 	printf("original: %d\nmine: %d\n", a, b);
// }
