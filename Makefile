NAME = bin/libftprintf.a
CC = cc
CFLAGS = -Werror -Wextra -Wall
DEBUG_CFLAGS = -ggdb

SRCS = src/ft_printf.c\
	src/dectohex.c

INCLUDE = include
LIBS = libft.a

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: $(wildcard src/*.c)
	$(CC) -ggdb -I$(INCLUDE) $^ -o $@ $(LIBS)
