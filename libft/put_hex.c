#include "libft.h"

/* Writes int <nbr> in hexadecimal, with the alphabet characters
in lowercase, to the file descripted by <fd> as chars. */
void	ft_puthex_fd(unsigned int nbr, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_puthex_fd(nbr / 16, fd);
		ft_putchar_fd(*(base + (nbr % 16)), 1);
	}
	else
		ft_putchar_fd(*(base + nbr), 1);
}

/* Writes int <nbr> in long hexadecimal, with the alphabet characters
in lowercase, to the file descripted by <fd> as chars. */
void	ft_putlonghex_fd(unsigned long nbr, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_putlonghex_fd(nbr / 16, fd);
		ft_putchar_fd(*(base + (nbr % 16)), fd);
	}
	else
		ft_putchar_fd(*(base + nbr), fd);
}

/* Writes int <nbr> in hexadecimal, with the alphabet characters
in uppercase, to the file descripted by <fd> as chars. */
void	ft_putupperhex_fd(unsigned int nbr, int fd)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_putupperhex_fd(nbr / 16, fd);
		ft_putchar_fd(*(base + (nbr % 16)), 1);
	}
	else
		ft_putchar_fd(*(base + nbr), 1);
}
