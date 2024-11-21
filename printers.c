#include "ft_printf.h"

void ft_putchar(va_list arg, int *len)
{
    char c;

    c = (char)va_arg(arg, int);
    write(1, &c, 1);
    *len += 1;
}
void ft_putstr(va_list arg, int *len)
{
    int i;
    char *s;
    
    s = va_arg(arg, char*);
    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    *len += i;
}
void print_mod(va_list arg, int *len)
{
    (void) arg;
    write(1, "%", 1);
    *len += 1;
}