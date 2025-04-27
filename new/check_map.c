#include "head.h"

int check_player_count(t_data *data)
{
    int i = -1;
    int j;
    int player_count = 0;

    while (data->map[++i])
    {
        j = -1;
        while (data->map[i][++j])
        {
            if (ft_strchr("NSEW", data->map[i][j]))
            {
                data->player_dir = data->map[i][j];
                player_count++;
            }
        }
    }
    if (player_count != 1)
    {
        printf("Error: Found %d players (expected 1)\n", player_count);
        return (1);
    }
    return (0);
}

int check_invalid_chars(t_data *data)
{
    int i = -1;
    int j;

    while (data->map[++i])
    {
        j = -1;
        while (data->map[i][++j])
        {
            if (!ft_strchr(" 01NSEW\n\t\0", data->map[i][j]))
            {
                printf("Error: Invalid char '%c' at [%d][%d]\n", 
                         data->map[i][j], i, j);
                return (1);
            }
        }
    }
    return (0);
}
int check_inner_empty_lines(t_data *data)
{
    int i = 0;
    bool map_started = false;
    bool map_ended = false;

    while (data->map[i])
    {
        if (!map_started && is_empty_line(data->map[i]))
        {
            i++;
            continue;
        }
        map_started = true;
        if (is_empty_line(data->map[i]))
            map_ended = true;
        else if (map_ended)
        {
            printf("Error: Empty line inside map at line %d\n", i + 1);
            return (1);
        }
        i++;
    }
    return (0);
}
//////////////////////////////////////////////////////////////////////////


int	check_pos(t_data *map, int x, int y, char *invalid_neighbors)
{
	if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || map->map[y][x] == 'W'
		|| map->map[y][x] == 'E')
	{
		if (x == 0 || !ft_strchr(invalid_neighbors, map->map[y][x - 1])
			|| !map->map[y][x + 1] || !ft_strchr(invalid_neighbors,
				map->map[y][x + 1]) || y == 0 || x >= (int)ft_strlen(map->map[y
				- 1]) || !ft_strchr(invalid_neighbors, map->map[y - 1][x])
			|| !map->map[y + 1] || x >= (int)ft_strlen(map->map[y + 1])
			|| !ft_strchr(invalid_neighbors, map->map[y + 1][x]))
			return (1);
	}
	return (0);
}


int	map_is_closed(t_data *map, int x, int i, char *valid_neighbors)
{
	i = 0;
	while ( i <  map->map_height )
	{  
		x = 0;
		while (map->map[i][x])
		{
			if (map->map[i][x] == '0')
			{
				if (x == 0 || !ft_strchr(valid_neighbors, map->map[i][x - 1])
					|| !map->map[i][x + 1] || !ft_strchr(valid_neighbors,
						map->map[i][x + 1]) || i == 0
					|| x >= (int)ft_strlen(map->map[i - 1])
					|| !ft_strchr(valid_neighbors, map->map[i - 1][x])
					|| !map->map[i + 1] || x >= (int)ft_strlen(map->map[i + 1])
					|| !ft_strchr(valid_neighbors, map->map[i + 1][x]))
					return (1);
			}
			if (check_pos(map, x, i, "10"))
				return (1);
			x++;
		}
		i ++ ;  
	}
	return (0);
}
int check_map(t_data *data)
{
    if (!data->map)
        return (1);
    
    if (check_invalid_chars(data) != 0)
        return (1);

    if (check_player_count(data) != 0)
        return (1);

    if (check_inner_empty_lines(data) != 0)
        return (1);

    if (map_is_closed(data, 0, 0, "10NEWS"))
        return (1);
    return (0);
}
