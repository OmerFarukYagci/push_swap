NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	   parse_first_utils.c \
	   parse_second_utils.c \
	   struct_utils.c \
	   parse_split.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): push_swap.h $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
