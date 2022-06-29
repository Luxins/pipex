NAME := pipex

OBJS = main.o ignore.o initalization.o
DIRS = libft/libft.a get_next_line/get_next_line.a

#	compilation
CFLAGS = -Werror -Wextra -Wall
CC = gcc
DEPS = pipex.h # only direct dependency

%.o: %.c $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C get_next_line
	$(CC) $^ $(DIRS) -o $@

all:	$(NAME)

clean:
	rm -f $(wildcard *.o)

fclean:	clean
	rm -f pipex

re:	fclean all