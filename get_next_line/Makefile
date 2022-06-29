NAME := get_next_line.a

SRC = get_next_line.c get_next_line_utils.c ripped_appart.c

BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE

${NAME}: $(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus: $(BONUS_OBJ)
	ar -rcs $(NAME) $(BONUS_OBJ)

all: $(NAME) infile

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re