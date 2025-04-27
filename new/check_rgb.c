#include "head.h"

int	hexa_color(t_data *data)
{
	if (data->C == NULL)
		return (1);
	if (valid_rgb(data->C))
		return (1);
	if (valid_rgb(data->F))
		return (1);
	set_rgb(data);
	return (0);
}

int	valid_rgb(char *rgb_str)
{
	char	*str_copy;
	char	*token;
	int		count;

	if( (!rgb_str) | ( (rgb_str[0] == ',' ) | ( rgb_str[ft_strlen(rgb_str) - 1] == ',' ) ))
		return 1;
	str_copy = ft_strdup(rgb_str);
	if (!str_copy)
		return (1);
	token = ft_strtok(str_copy, ",");
	count = 0;
	while (token)
	{
		if (is_valid_number(token))
		{
			free(str_copy);
			return (1);
		}
		count++;
		token = ft_strtok(NULL, ",");
	}
	free(str_copy);
	if (count != 3)
		return (1);
	return (0);
}

int	is_valid_number(const char *str)
{
	int	i;
	int	num;

	i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (1);
		i++;
	}
	num = ft_atoi(str);
	if (num < 0 || num > 255)
		return (1);
	return (0);
}
void set_rgb(t_data *data)
{
    char **rgb;
    int i;

    if (data->F)
    {
        rgb = ft_split(data->F, ',');
        if (rgb && rgb[0] && rgb[1] && rgb[2] && !rgb[3])
        {
            data->r_f = ft_atoi(rgb[0]);
            data->g_f = ft_atoi(rgb[1]);
            data->b_f = ft_atoi(rgb[2]);
        }
        i = 0;
        while (rgb && rgb[i])
            free(rgb[i++]);
        free(rgb);
    }

    if (data->C)
    {
        rgb = ft_split(data->C, ',');
        if (rgb && rgb[0] && rgb[1] && rgb[2] && !rgb[3])
        {
            data->r_c = ft_atoi(rgb[0]);
            data->g_c = ft_atoi(rgb[1]);
            data->b_c = ft_atoi(rgb[2]);
        }
        i = 0;
        while (rgb && rgb[i])
            free(rgb[i++]);
        free(rgb);
    }
}
