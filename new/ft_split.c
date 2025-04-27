#include "head.h"


void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p_d;
	unsigned char	*p_s;
	size_t			i;

	i = 0;
	p_d = (unsigned char *)dest;
	p_s = (unsigned char *)src;
	while (i < n)
	{
		p_d[i] = p_s[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*result;

	len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*result;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
	{
		return (ft_strdup(""));
	}
	if (len > slen - start)
		len = slen - start;
	result = (char *)malloc(len + 1 * sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}

static size_t	str_count(char *s1, char c)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 1;
	if (s1[0] == c || s1[0] == '\0')
		result = 0;
	while (s1[i])
	{
		if (s1[i] == c && s1[i + 1] != c && s1[i + 1] != '\0')
		{
			result++;
		}
		i++;
	}
	return (result);
}

static void	ft_free(char **s, int i)
{
	while (i >= 0)
		free(s[i--]);
	free(s);
}

static size_t	*ft_while(char const *s, char c, char **arrstr)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	word_count;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (start < end)
		{
			arrstr[word_count] = ft_substr(s, start, end - start);
			if (arrstr[word_count] == NULL)
				ft_free(arrstr, word_count);
			word_count++;
		}
	}
	return ((size_t *)word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**arrstr;
	size_t	result;

	if (!s)
		return (NULL);
	result = str_count((char *)s, c);
	arrstr = (char **)malloc((result + 1) * sizeof(char *));
	if (arrstr == NULL)
		return (NULL);
	arrstr[result] = NULL;
	ft_while(s, c, arrstr);
	return (arrstr);
	ft_while(s, c, arrstr);
	return (arrstr);
}



char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	if (!ft_strlen(s1))
		return (ft_strdup(""));
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end - 1]))
		end--;
	result = ft_substr(s1, start, end - start);
	if (!result)
		return (NULL);
	return (result);
}
