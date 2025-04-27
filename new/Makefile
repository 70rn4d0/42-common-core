CC = cc -Wall -Wextra -Werror -fsanitize=address

 
SRC = gnl/get_next_line_utils.c gnl/get_next_line.c \
	parsing.c help_function.c file_read.c ft_split.c check_map.c \
	cheak_textures.c check_rgb.c utils.c

OBJS = $(SRC:.c=.o)

TARGET = test

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
