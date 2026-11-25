NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = swp.c psh.c rrtt.c rtt.c operlist.c main.c check_error.c utls.c \
	sort_big.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -Llibft -lft -Llibft/ft_printf -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C libft
	make clean -C libft/ft_printf
	make clean -C libft/get_next_line

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	make fclean -C libft/ft_printf
	make fclean -C libft/get_next_line

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
