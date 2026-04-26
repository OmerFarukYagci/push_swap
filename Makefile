NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	   parse_first_utils.c \
	   parse_second_utils.c \
	   struct_utils.c \
	   parse_split.c \
	   sorting_first_algorithm.c \
	   sorting_second_algorithm.c \
	   sorting_third_algorithm.c \
	   complex_algorithm.c \
	   simple_algorithm.c \
	   bench_utils.c \
	   medium_algorithm.c \
	   medium_algorithm_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
