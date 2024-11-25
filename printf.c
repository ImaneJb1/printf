/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:29:02 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/25 20:37:14 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*init_func(void)
{
	static t_format	arr[] = {{'c', ft_printchar}, {'s', ft_putstr}, {'d',
		ft_putnbr}, {'i', ft_putnbr}, {'u', ft_put_unsigned_nbr}, {'x',
		ft_put_lowhexa_nbr}, {'X', ft_put_upphexa_nbr}, {'p', put_0x}};

	return (arr);
}

void	specifier_handler(t_format *arr, const char *character, va_list arg,
		int *len)
{
	int	j;

	j = 0;
	if (*character == '%')
	{
		*len += write(1, "%", 1);
		return ;
	}
	while (j < 9)
	{
		if (*character == arr[j].specifier)
		{
			arr[j].function_pointer(va_arg(arg, unsigned long), len);
			return ;
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
			if (!format[i])
				return(len);
			specifier_handler(arr, &format[i], arg, &len);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(arg);
	return (len);
}
#include <limits.h>
int	main(void)
{
	printf("%");
	// ft_printf("zzzzz");
	// while(1)
	// {
		
	// }

}
