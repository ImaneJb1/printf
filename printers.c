#include "ft_printf.h"


void ft_putchar(char c, int *len)
{   
    write(1, &c, 1);
    *len += 1;
}

void ft_printchar(unsigned long n, int *len)
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
    if(s == NULL)
	{
		*len += write(1, "(null)", 6);
		return;
	}
	i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    *len += i;
}


void    ft_put_unsigned_nbr(unsigned long n, int *len)
{
    unsigned int nb;
	unsigned int nbr;

	nbr = (unsigned int)n;
    nb = n;
    if (nbr > 9)
	{
		ft_put_unsigned_nbr(nbr / 10, len);
		ft_put_unsigned_nbr(nbr % 10, len);
	}
	if (nbr <= 9)
	{
		ft_putchar(nbr + 48, len);
	}
}

void	ft_putnbr(unsigned long n, int *len)
{
    int nb;
    nb = (int)n;
  
    if (nb == -2147483648)
	{
		*len += write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', len);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	if (nb <= 9)
	{
        ft_putchar(nb + 48, len);
	}
}

void	ft_put_lowhexa_nbr(unsigned long n, int *len)
{
    char *base = "0123456789abcdef";
	unsigned int nbr;

	nbr = (unsigned int)n;
	if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr = -nbr;
	}
	if (nbr > 15)
	{
		ft_put_lowhexa_nbr(nbr / 16, len);
		ft_put_lowhexa_nbr(nbr % 16, len);
	}
	if (nbr <= 15)
	{
        ft_putchar(base[nbr], len);
	}
}

void	ft_put_upphexa_nbr(unsigned long n, int *len)
{
    char *base = "0123456789ABCDEF";
	unsigned int nbr;

	nbr = (unsigned int)n;
    if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr = -nbr;
	}
	if (nbr > 15)
	{
		ft_put_upphexa_nbr(nbr / 16, len);
		ft_put_upphexa_nbr(nbr % 16, len);
	}
	if (nbr <= 15)
	{
        ft_putchar(base[nbr], len);
	}
}

void put_0x(unsigned long n, int *len)
{

	ft_putchar('0', len);
	ft_putchar('x', len);
	ft_putaddress(n, len);
}
void ft_putaddress(unsigned long n, int* len)
{
	char *base = "0123456789abcdef";
	
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
	}
	if (n > 15)
	{
		ft_putaddress(n / 16, len);
		ft_putaddress(n % 16, len);
	}
	if (n <= 15)
	{
        ft_putchar(base[n], len);
	}
}