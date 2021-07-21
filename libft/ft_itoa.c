#include "libft.h"

static char	*allomem(int n, int len)
{
	char	*output;

	if (n != 0)
		output = malloc(len + 1);
	else
		output = malloc(2);
	if (!output)
		return (NULL);
	return (output);
}

static void	fill(char *out, long n, int len)
{
	if (n < 0)
	{
		*out = '-';
		fill(out, n * -1, len);
	}
	else if (n > 0)
	{
		*(out + len - 1) = '0' + (n % 10);
		fill(out, n / 10, len - 1);
	}
}

/* Creates -using malloc- a string that containts <n> as chars */
char	*ft_itoa(int n)
{
	char	*output;
	int		len;

	len = ft_digitcount(n);
	if (n < 0)
		len++;
	output = allomem(n, len);
	if (!output)
		return (NULL);
	if (n != 0)
	{
		fill(output, (long)n, len);
		*(output + len) = '\0';
	}
	else
	{
		*output = '0';
		*(output + 1) = '\0';
	}
	return (output);
}
