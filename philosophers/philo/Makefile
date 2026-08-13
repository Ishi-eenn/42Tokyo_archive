NAME		=	philo
CC			=	cc
INCLUDE		=	-I./includes
FLAGS		=	-Wall -Wextra -Werror -pthread
# FLAGS		=	-Wall -Wextra -Werror -pthread -g -fsanitize=thread
RM			=	rm -rf

UTILS_DIR	=	utils
UTIL		=	exit.c \
				ft_atoi.c \
				ft_isdigit.c \
				ft_putchar.c \
				ft_putstr_fd.c \
				ft_strtol.c \
				get_time.c \
				print.c \
				wait.c
UTILS		=	$(addprefix $(UTILS_DIR)/, $(UTIL))

INPUT_DIR	=	input
INPUT		=	is_arguments.c \
				is_below_threshold.c \
				is_count.c \
				is_numeric.c \
				input.c \
				is_integer_arguments.c \
				is_eating_limit.c
INPUTS		=	$(addprefix $(INPUT_DIR)/, $(INPUT))

INIT_DIR	=	init
INIT		=	data_structures.c \
				last_eaten_times.c \
				mutex.c \
				philo.c \
				table.c
INITS		=	$(addprefix $(INIT_DIR)/, $(INIT))

DINING_DIR	=	dining
DINING		=	create_death_monitor_thread.c \
				create_philosopher_threads.c \
				create_eat_limit_monitor_thread.c \
				cutlery.c \
				cycle.c \
				eat.c \
				death.c \
				dining.c \
				routine.c
DININGS		=	$(addprefix $(DINING_DIR)/, $(DINING))

SRC_DIR		=	srcs
SRC			=	$(UTILS) \
				$(INPUTS) \
				$(INITS) \
				$(DININGS) \
				main.c

SRCS	= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR	= objs
OBJS	= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDE) $(SRCS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ mkdir -p $(@D)
	$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<

all: $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
