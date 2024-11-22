#ifndef HEADER_H
# define HEADER_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef struct format
{
    char specifier;
    void (*function_pointer)(va_list, int *);
}format_t;

typedef struct variables
{
	format_t *arr;
    int		i;
	int		j;
	int		len;
	va_list	arg;
	int		check;

}			var_t;

void ft_putchar(va_list arg, int *len);
void ft_putstr(va_list arg, int *len);
void print_mod(va_list arg, int *len);
#endif