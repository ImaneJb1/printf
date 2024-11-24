#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_format
{
	char	specifier;
	void	(*function_pointer)(unsigned long, int *);
}			t_format;

void		ft_putchar(unsigned long arg, int *len);
void		ft_putstr(unsigned long arg, int *len);
void		print_mod(unsigned long arg, int *len);
void		ft_putnbr(unsigned long arg, int *len);
void		_putchar(char c, int *len);

#endif