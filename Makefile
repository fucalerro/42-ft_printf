# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = libft/libft.a
PRINTF_SRC = $(filter-out test_printf.c, $(wildcard *.c))
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

# Default rule
all: $(NAME)

# This won't be called if the files don't exist or are not updated
$(PRINTF_OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(PRINTF_OBJ)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(PRINTF_OBJ)

clean:
	make clean -C libft
	rm -f $(PRINTF_OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# NAME			=	libftprintf.a
# CC				=	cc
# CFLAGS			=	-Werror -Wextra -Wall
# DEBUG_CFLAGS	=	-ggdb
# AR				=	ar
# AR_FLAGS		=	rc

# SRCS			=	src/ft_printf.c\
# 					src/helpers.c\
# 					src/hex_helpers.c\
# 					src/printers.c

# INCLUDE			=	include
# LIBFT_PATH		=	./libft
# LIBFT			=	$(LIBFT_PATH)/libft.a

# OBJS			=	$(SRCS:.c=.o)

# %.o :				%.c
# 					$(CC) $(CFLAGS) -c -o $@ $^

# all:				$(NAME)

# $(NAME):			$(LIBFT) $(OBJS)
# 				cp	$(LIBFT) $(NAME)
# 					$(AR) $(AR_FLAGS) $(NAME) $(OBJS)

# $(LIBFT):
# 					make -C $(LIBFT_PATH) all

# clean:
# 					make -C $(LIBFT_PATH) clean
# 					rm -rf $(OBJS)

# fclean: clean
# 					make -C $(LIBFT_PATH) fclean
# 					rm -f $(NAME)

# re: 				fclean all

# debug:				$(wildcard src/*.c)
# 					$(CC) -ggdb -I$(INCLUDE) $^ -o $@ $(LIBS)
