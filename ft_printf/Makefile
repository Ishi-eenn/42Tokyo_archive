NAME	= libftprintf.a
AR		= ar rc
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
SRCS	= ft_putchar.c ft_printf.c ft_puthex.c ft_putstr.c ft_putnbr.c ft_putptr.c ft_judge_format.c ft_printf.c ft_putunbr.c
OBJS	= $(SRCS:%.c=%.o)

all: ${NAME}

${NAME}: ${OBJS}
		${AR} ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all
