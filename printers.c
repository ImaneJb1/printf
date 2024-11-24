#include "ft_printf.h"

void _putchar(char c, int *len)
{   
    write(1, &c, 1);
    *len += 1;
}

void ft_putchar(unsigned long n, int *len)
{
    char c;

    c = n;
    write(1, &c, 1);
    *len += 1;
}
void ft_putstr(unsigned long n, int *len)
{
    int i;
    char *s;
    
    s = (char*)n;
    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    *len += i;
}
void print_mod(unsigned long n, int *len)
{
    (void) n;
    write(1, "%", 1);
    *len += 1;
}

void    ft_put_unsigned_nbr(unsigned long n, int *len)
{
    unsigned int nb;

    nb = n;
    if (n > 9)
	{
		ft_put_unsigned_nbr(n / 10, len);
		ft_put_unsigned_nbr(n % 10, len);
	}
	if (n <= 9)
	{
		_putchar(n + 48, len);
	}
}

void	ft_putnbr(unsigned long n, int *len)
{
    int nb;
    nb = (int)n;
  
    if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		_putchar('-', len);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	if (nb <= 9)
	{
        _putchar(nb + 48, len);
	}
}
