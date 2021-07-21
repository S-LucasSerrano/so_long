#include "libft.h"

/* Compares no more than <n> chars of <str1> and <str2>.
Returns the difference (*str1 - *str2) between the first different char.
0 if the no difference is found. */
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (*str1 != '\0' && *str2 != '\0' && n--)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		str1++;
		str2++;
	}
	if (n != 0 && (*str1 == '\0' || *str2 == '\0'))
		return ((unsigned char)*str1 - (unsigned char)*str2);
	return (0);
}

/* Returns 1 if <name> ends in <extension>, 0 if not */
int	ft_strend_cmp(char *name, char *end)
{
	int	name_len;
	int	ext_len;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(end);
	if (name_len <= ext_len)
		return (0);
	name += name_len - ext_len;
	while (*name)
	{
		if (*name != *end)
			return (0);
		name++;
		end++;
	}
	return (1);
}

/* Returns a pointer to the first char
of the first occurrence of <little> in <big>.
If <little> is an empty string, <big> is returned.
if <big> not includes <little>, NULL is returned. */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len > 0)
	{
		if (*big == *little)
		{
			i = 0;
			while (little[i] != '\0' && len - i > 0)
			{
				if (little[i] != big[i])
					break ;
				i++;
			}
			if (little[i] == '\0')
				return ((char *)big);
		}
		len--;
		big++;
	}
	return (NULL);
}
