NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_hex.c ft_putnbr_unsigned.c ft_putstr.c ft_putptr.c

OBJS = $(SRCS:.c=.o)


$(NAME) : $(OBJS)
	ar rc $@ $?

all: $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
