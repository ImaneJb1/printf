/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:29:02 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/22 11:56:15 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

format_t	*init_func(void)
{
	static format_t	arr[3] = {{'c', ft_putchar}, {'s', ft_putstr}, {'%',
			print_mod}};

	return (arr);
}

int	specifier_handler(format_t *arr, const char *character, va_list arg, int *len)
{ 
	int	j;
		j = 0;
		while (j < 3)
		{
			if (*character == arr[j].specifier)
			{
				arr[j].function_pointer(arg, len);
				return (1);
			}
			j++;
		}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	format_t	*arr;
	va_list		arg;
	int			len;
	int			i;

	arr = init_func();
	va_start(arg, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if(format[i] == '%')
		{
			i++;
			if (specifier_handler(arr, &format[i], arg, &len) == 0)
				write(1, &format[i], 1);
		}
		else	
				write(1, &format[i], 1);
		i++;

	}
	return (len);
}

// int	main(void)
// {
// 	// printf("Got: ");
// 	// ft_printf("imane %l and %s imane %%  \n", 'j', "jb");
// 	// printf("Expected: ");
// 	printf("imane %c %s \n", 5, "jb");
// }
