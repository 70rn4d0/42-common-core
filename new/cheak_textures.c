#include "head.h"

int	file_extension(char *av, bool c)
{
	char	*ext;

	ext = ft_strrchr(av, '.');
	if (ext == NULL)
		return (1);
	if (c == 0)
		if (ft_strcmp(ext, ".cub") != 0)
			return (1);
	if (c == 1)
		if (ft_strcmp(ext, ".xpm") != 0)
			return (1);
	return (0);
}

int	file_permission(char *map)
{
	int	fd;
	fd = open(map, O_RDONLY) ;
	if (fd == -1)
	return (1);
	close(fd);
	return (0);
}

int	open_file(char *map, int fd)
{   
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (1);
	return (fd);
}

int	ft_wordcount(const char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == ' ' || *str == '\t')
			in_word = 0;
		str++;
	}
	return (count);
}

int	texture_permission(t_data *data)
{    

	if(ft_wordcount(data->so) != 1 || ft_wordcount(data->no) != 1
		|| ft_wordcount(data->we) != 1 || ft_wordcount(data->ea) != 1)
		{
			printf("-------(check the texture)--------\n");  
			return (1) ;
		}
		
	if (file_permission(data->no))
		{ 
			printf("%s is  failled \n " ,  data->no ) ;  
			return (1) ; 
		}   
	if (file_permission(data->ea))
	 {  
		printf("%s is  failled \n " ,  data->ea ) ;   
		return (1);
	 }  
	if (file_permission(data->so) )  
	{  
		printf("%s is  failled \n " ,  data->no )  ;  
		return (1);
	}  
		if (file_permission(data->we))
		{ 
			printf("%s is  failled \n " ,  data->we) ;   
			return (1);
		}  
		return (0);
}
