#ifndef HEAD_H
# define HEAD_H

# include "./gnl/get_next_line.h"
# include <ctype.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <string.h> 
typedef struct s_parsing_data
{
	char	*no;
	char	*ea;
	char	*so;
	char	*we;  
	int     r_f;
    int     g_f;
    int     b_f; 
	int		r_c; 
	int		g_c;
	int		b_c;
	char	**map;
	char	player_dir;
	int		map_height;
	int		map_width;
	char	*F;
	char	*C;

}			t_data;

int	parse_check(char **av, t_data *data);
void init_parsing_data(t_data *data);
int	file_extension(char *av, bool c);
int	file_permission(char *map);
int	open_file(char *map, int fd);
int	texture_permission(t_data *data);
int	ft_strcmp( char *s1,  char *s2);
int	ft_atoi(const char *nptr);
char	*ft_strrchr( char *s, int c);
int read_file(char *filename, t_data *data, int fd);
int is_spaces_only(char *line);
int is_empty_line(char *line);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
int check_map(t_data *data);
void free_2d_array(char **arr);
int	open_file(char *map, int fd);
int	texture_permission(t_data *data);
int	hexa_color(t_data *data);
int	valid_rgb( char *rgb_str);
int	is_valid_number(const char *str);
char	*ft_strtok(char *str, const char *delim);
int check_player_count(t_data *data);
void set_rgb(t_data *data);

#endif
