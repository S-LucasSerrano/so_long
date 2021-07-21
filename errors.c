#include <stdio.h>

/* Returns 0 printing <message> in red */
int	error(char *message)
{
	printf("\033[0;31m" " ERROR : %s\n" "\033[0m", message);
	return (0);
}

/* Returns NULL printing <message> in red */
void	*null_error(char *message)
{
	printf("\033[0;31m" " ERROR : %s\n" "\033[0m", message);
	return (0);
}

/* Prints <message> in yellow */
void	print_warning(char *message)
{
	printf("\033[0;33m" " WARNING : %s\n" "\033[0m", message);
}
