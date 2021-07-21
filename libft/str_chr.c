#include "libft.h"

/* Returns a pointer to the FIRST occurrence of the character c 
in the string str, or NULL if the character is not found */
char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

/* Returns a pointer to the LAST occurrence of the character c 
in the string str, or NULL if the character is not found */
char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str) + 1;
	while (len--)
	{
		if (*(str + len) == (char)c)
			return ((char *)str + len);
	}
	return (NULL);
}

/* Returns a pointer to the FIRST ocurrence of a char
in <str> that is not included in <set> */
char	*ft_strdiffc(const char *str, const char *set)
{
	if (str != NULL && set != NULL)
	{
		while (*str)
		{
			if (!ft_strchr(set, *str))
				return ((char *)str);
			str++;
		}
		if (!ft_strchr(set, *str))
			return ((char *)str);
	}
	return (NULL);
}

/* Returns a pointer to the LAST ocurrence of a char
in <str> that is not included in <set> */
char	*ft_strrdiffc(const char *str, const char *set)
{
	int	len;

	if (str != NULL && set != NULL)
	{
		len = ft_strlen(str);
		while (len >= 0)
		{
			if (!ft_strchr(set, *(str + len)))
				return ((char *)str + len);
			len--;
		}
		if (!ft_strchr(set, *str))
			return ((char *)str + len);
	}
	return (NULL);
}
