#include "head.h"

void ft_free(t_data *data)
{
    if (!data)
        return;

    if (data->no) free(data->no);
    if (data->so) free(data->so);
    if (data->we) free(data->we);
    if (data->ea) free(data->ea);
    if (data->F) free(data->F);
    if (data->C) free(data->C);

    if (data->map)
    {
        int i = 0;
        while (data->map[i])
            free(data->map[i++]);
        free(data->map);
    }

    data->no = NULL;
    data->so = NULL;
    data->we = NULL;
    data->ea = NULL;
    data->F = NULL;
    data->C = NULL;
    data->map = NULL;
    
    data->map_height = 0;
    data->map_width = 0;
}

void	ft_printf(t_data *data)
{
	if (!data->map)
	{
		printf("Map is empty or not initialized.\n");
		return ;
	}
	printf("Parsed Map:\n");
	for (int i = 0; i < data->map_height; i++)
	{
		printf("[%d]: \"%s\" (length: %zu)\n", i, data->map[i], strlen(data->map[i]));
	}
	printf("Map Height: %d, Map Width: %d\n", data->map_height, data->map_width);
	printf("-----------------------------------------\n");
	printf("we---> %s\n", data->we);
	printf("no--> %s\n", data->no);
	printf("ea---> %s\n", data->ea);
	printf("so -->%s\n", data->so);
	printf("F--> %s\n", data->F);
	printf("C --> %s\n", data->C);
	printf("player_dir---> %c\n", data->player_dir);
	printf("r_c---> %d\n", data->r_c);
	printf("g_c--> %d\n", data->g_c);
	printf("b_c---> %d\n", data->b_c);
	printf("r_f---> %d\n", data->r_f);
	printf("g_f--> %d\n", data->g_f);
	printf("b_f->> %d\n", data->b_f);
	printf("map_height --> %d\n", data->map_height);
	printf("map_width--> %d\n", data->map_width);	
}

int	parse_check(char **av, t_data *data)
{
	if (file_extension(av[1], 0))	
	{
		printf("[DEBUG] file_extension failed\n");
		return (1); 
	}
	if (file_permission(av[1]))
	{
		printf("[DEBUG] file_permission failed\n");
		return (1);
	}
	if (read_file(av[1], data, -1))
	{
		printf("[DEBUG] read_file failed\n");
		return (1);
	}
	if(check_map(data))
	{
		printf("[DEBUG] check_map failed\n");
		return (1);
	}
	if (texture_permission(data))
	{
		printf("[DEBUG] texture_permission failed\n");
		return (1);
	}
	if (hexa_color(data))
	{
		printf("[DEBUG] hexa_color failed\n");
		return (1);
	}
	ft_printf(data);
	return (0);
}
void init_parsing_data(t_data *data)
{
    data->no = NULL;
    data->ea = NULL;
    data->so = NULL;
    data->we = NULL;
    
    data->r_f = 0;
    data->g_f = 0;
    data->b_f = 0;
    
    data->r_c = 0;
    data->g_c = 0;
    data->b_c = 0;
    
    data->map = NULL;
    data->player_dir = '\0';
    data->map_height = 0;
    data->map_width = 0;
    
    data->F = NULL;
    data->C = NULL;
}

int main(int ac, char **av)  
{  
	t_data  data;    
	if (ac != 2)
    {
        printf("Error: Wrong argument count\n");
        exit(3);
    }
	init_parsing_data(&data);
	if (parse_check(av, &data))
	{
		ft_free(&data);   
		write(1, "error ❌\n", 11) ;
		exit(2);   
	}    
	ft_free(&data);
	return  0;
}
