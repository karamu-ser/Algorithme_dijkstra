SRCS = $(wildcard *.c)
OBJ = $(SRCS:.c=.o)
NAME = dijkstra
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ): %.o : %.c header.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all

run:	$(NAME)
	./$(NAME)