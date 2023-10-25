NAME			=	libftprintf.a
CC				=	cc
CFLAGS			=	-Werror -Wextra -Wall
DEBUG_CFLAGS	=	-ggdb
AR				=	ar
AR_FLAGS		=	rc
SRCS			=	ft_printf.c\
					helpers.c\
					hex_helpers.c\
					printers.c
INCLUDE			=	include
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a
OBJS			=	$(SRCS:.c=.o)

%.o :				%.c
					$(CC) $(CFLAGS) -c -o $@ $^

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJS)
				cp	$(LIBFT) $(NAME)
					$(AR) $(AR_FLAGS) $(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIBFT_PATH) all

clean:
					make -C $(LIBFT_PATH) clean
					rm -rf $(OBJS)

fclean: clean
					make -C $(LIBFT_PATH) fclean
					rm -f $(NAME)

re: 				fclean all

debug:				$(wildcard src/*.c)
					$(CC) -ggdb -I$(INCLUDE) $^ -o $@ $(LIBS)

.PHONY: all clean fclean re
