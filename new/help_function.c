#include "head.h"

int	ft_strcmp( char *s1,  char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

char	*ft_strrchr( char *s, int c)
{
	int	l;

	l = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)&s[l]);
	l -= 1;
	while (l >= 0)
	{
		if (s[l] == (unsigned char)c)
			return ((char *)&s[l]);
		l--;
	}
	return (NULL);
}
int is_spaces_only(char *line)
{
    int i;

    if (!line)
        return (0);

    i = 0;
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return (0);
        i++;
    }

    return (1);
}

int is_empty_line(char *line)
{
    if (!line)
        return (0);
    if (line[0] == '\n' && line[1] == '\0')
        return (1);

    return (0);
}
