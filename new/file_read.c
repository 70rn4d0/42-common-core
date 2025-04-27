#include "head.h"

void free_2d_array(char **arr)
{
    int i;

    if (!arr)
        return;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

char *ft_strtrim_end(char const *s, char const *set)
{
    char *end;
    
    if (!s || !set)
        return (NULL);
    
    end = (char *)s + ft_strlen(s) - 1;
    while (end >= s && ft_strchr(set, *end))
        end--;
    
    return (ft_substr(s, 0, end - s + 1));
}

static int store_configuration(char *key, char *value, t_data *data)
{
    if (ft_strcmp(key, "NO") == 0 && !data->no)
        data->no = ft_strdup(value);
    else if (ft_strcmp(key, "SO") == 0 && !data->so)
        data->so = ft_strdup(value);
    else if (ft_strcmp(key, "WE") == 0 && !data->we)
        data->we = ft_strdup(value);
    else if (ft_strcmp(key, "EA") == 0 && !data->ea)
        data->ea = ft_strdup(value);
    else if (ft_strcmp(key, "F") == 0 && !data->F)
        data->F = ft_strdup(value);
    else if (ft_strcmp(key, "C") == 0 && !data->C)
        data->C = ft_strdup(value);
    else
        return (1);
    
    return (0);
}

int process_config_line(char *line, t_data *data)
{
    char *key;
    char *value;
    int i = 0;

    while (line[i] == ' ' || line[i] == '\t')
        i++;

    int key_start = i;
    while (line[i] && line[i] != ' ' && line[i] != '\t')
        i++;
    if (i == key_start)
        return (1);

    key = ft_substr(line, key_start, i - key_start);

    while (line[i] == ' ' || line[i] == '\t')
        i++;

    int value_start = i;
    while (line[i] && line[i] != '\n')
        i++;
    while (i > value_start && (line[i-1] == ' ' || line[i-1] == '\t'))
        i--;

    if (i == value_start)
    {
        free(key);
        return (1); 
    }
    value = ft_substr(line, value_start, i - value_start);

    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (line[i] && line[i] != '\n')
    {
        free(key);
        free(value);
        return (1);
    }
    int result = store_configuration(key, value, data);
    free(key);
    free(value);
    return (result);
}
int store_raw_map_line(char *line, t_data *data)
{
    char **new_map;
    int i;

    new_map = malloc((data->map_height + 2) * sizeof(char *));
    if (!new_map)
        return (1);

    i = -1;
    while (++i < data->map_height)
        new_map[i] = data->map[i];

    new_map[data->map_height] = ft_strdup(line);
    new_map[data->map_height + 1] = NULL;

    free(data->map);
    data->map = new_map;
    data->map_height++;

    if ((int)ft_strlen(line) > data->map_width)
        data->map_width = ft_strlen(line);

    return (0);
}

int read_file(char *filename, t_data *data, int fd)
{
    char *line;
    bool configs_done = false;

    fd = open_file(filename, -1);
    if (fd == -1)
        return (1);

    while ((line = get_next_line(fd)))
    {
        // Phase 1: Parse configs
        if (!configs_done && !is_empty_line(line))
        {
            if (process_config_line(line, data))
            {
                free(line);
                close(fd);
                return (1);
            }

            if (data->no && data->so && data->we && data->ea && data->F && data->C)
                configs_done = true;
        }
        // Phase 2: Store ALL lines
        else if (configs_done)
        {
            if (store_raw_map_line(line, data))
            {
                free(line);
                close(fd);
                return (1);
            }
        }
        free(line);
    }
    close(fd);
    return (0);
}