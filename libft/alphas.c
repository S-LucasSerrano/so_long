#include "libft.h"

/* Returns 1 if <c> is a letter. 0 if not. */
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/* Returns 1 if <c> is a uppercase letter.
0 if it is a lowercase.
And -1 if it is not a letter. */
int	ft_isupperalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (0);
	return (-1);
}

/* Returns the UPPERCASE of a letter.
And the same char if it isn't a lower case letter */
int	ft_toupper (int c)
{
	if (ft_isalpha(c) && c >= 'a')
		return (c - 32);
	return (c);
}

/* Returns the LOWERCASE of a letter.
And the same char if it isn't an upper case letter */
int	ft_tolower (int c)
{
	if (ft_isalpha(c) && c <= 'Z')
		return (c + 32);
	return (c);
}
