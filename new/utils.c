#include "head.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*save_ptr = NULL;
	char		*token;

	if (!str)
	{
		if (!save_ptr)
			return (NULL);
		str = save_ptr;
	}
	while (*str && ft_strchr(delim, *str))
		str++;
	if (!*str)
	{
		save_ptr = NULL;
		return (NULL);
	}
	token = str;
	while (*str && !ft_strchr(delim, *str))
		str++;
	if (*str)
	{
		*str = '\0';
		save_ptr = str + 1;
	}
	else
		save_ptr = NULL;
	return (token);
}

