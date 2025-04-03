NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

RM = rm -rf

SRCS = swp.c psh.c rrtt.c rtt.c operlist.c main.c check_error.c utls.c radix.c

OBJS = $(SRCS:.c=.o)


$(NAME):	$(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -Llibft -lft -Llibft/ft_printf -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C libft 
	make clean -C libft/ft_printf
	make clean -C libft/get_next_line

fclean: clean
	$(RM) $(NAME) $(OBJS)
	make fclean -C libft
	make fclean -C libft/ft_printf
	make fclean -C libft/get_next_line

re: fclean all
