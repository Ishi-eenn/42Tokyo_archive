CC			= cc
CFLAGS		= -Wall -Werror -Wextra
SRCS		= main.c utils.c free.c utils_stack.c sort.c sort_utils.c get_input.c sort_utils2.c \
				push.c rotate.c reverse_rotate.c swap.c libft.c check.c
BONUS_SRCS	= checker_bonus.c check_operations_bonus.c free_bonus.c utils_stack_bonus.c get_input_bonus.c \
				push_bonus.c rotate_bonus.c reverse_rotate_bonus.c swap_bonus.c libft_bonus.c \
				get_next_line_bonus.c get_next_line_utils_bonus.c check_bonus.c
OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
NAME		= push_swap
BONUS_NAME	= checker
RM			= rm -f

all : $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) -o $(BONUS_NAME) $(CFLAGS) $(BONUS_OBJS)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

test: all bonus
	bash test.sh

visual: all
	bash pain.sh

.PHONY : all clean fclean re
