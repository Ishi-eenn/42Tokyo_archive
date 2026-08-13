NAME		=	fdf
CC			=	cc
INCLUDE 	=	includes
CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE)
# CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g -I$(INCLUDE)
RM			=	rm -f


LIBFT_DIR	=	libft
LIBFT		=	libft.a
LIBFTS		=	$(addprefix $(LIBFT_DIR)/, $(LIBFT))

GNL_DIR		=	get_next_line
GNL			=	libgnl.a
GNLS		=	$(addprefix $(GNL_DIR)/, $(GNL))

MLX_DIR		=	minilibx
MLX			=	libmlx.a
MLXS		=	$(addprefix $(MLX_DIR)/, $(MLX))

SRCS		=	fdf.c srcs/init.c srcs/alg_utils.c srcs/controls.c srcs/color.c \
				srcs/rotate.c srcs/mouse.c srcs/keyboard.c srcs/draw.c \
				srcs/line_alg.c srcs/project.c srcs/parse_map.c srcs/utils.c

OBJS		=	$(SRCS:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFTS) $(GNLS) $(MLXS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl -L$(MLX_DIR) -lmlx -lm -o $(NAME) -framework OpenGL -framework AppKit
	@ echo " _______ _____  _______    _______ _____  _______    _______ _____  _______    "
	@ echo "|    ___|     \|    ___|  |    ___|     \|    ___|  |    ___|     \|    ___|   "
	@ echo "|    ___|  --  |    ___|  |    ___|  --  |    ___|  |    ___|  --  |    ___|   "
	@ echo "|___|   |_____/|___|      |___|   |_____/|___|      |___|   |_____/|___|       "
	@ echo " _______ _____  _______    _______ _____  _______    _______ _____  _______    "
	@ echo "|    ___|     \|    ___|  |    ___|     \|    ___|  |    ___|     \|    ___|   "
	@ echo "|    ___|  --  |    ___|  |    ___|  --  |    ___|  |    ___|  --  |    ___|   "
	@ echo "|___|   |_____/|___|      |___|   |_____/|___|      |___|   |_____/|___|       "
	@ echo " _______ _____  _______    _______ _____   _______    _______ _____  _______   "
	@ echo "|    ___|     \|    ___|  |    ___|     \|    ___|  |    ___|     \|    ___|   "
	@ echo "|    ___|  --  |    ___|  |    ___|  --  |    ___|  |    ___|  --  |    ___|   "
	@ echo "|___|   |_____/|___|      |___|   |_____/|___|      |___|   |_____/|___|       "

$(LIBFTS):
	$(MAKE) -s -C $(LIBFT_DIR)

$(GNLS):
	$(MAKE) -s -C $(GNL_DIR)

$(MLXS):
	$(MAKE) -s -C $(MLX_DIR)

bonus:	all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -s -C $(LIBFT_DIR)
	$(MAKE) clean -s -C $(GNL_DIR)
	$(MAKE) clean -s -C $(MLX_DIR)

fclean:
	$(RM) $(OBJS)
	$(MAKE) fclean -s -C $(LIBFT_DIR)
	$(MAKE) fclean -s -C $(GNL_DIR)
	$(MAKE) clean -s -C $(MLX_DIR)
	$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
