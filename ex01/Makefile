NAME		=	RPN
CXX			=	c++

INCLUDE		=	-I./includes
FLAGS		=	-std=c++98 -Wall -Wextra -Werror -pedantic
DEPFLAGS	=	-MMD -MP
RM			=	rm -rf

SRC_DIR		=	srcs
SRC			=	main.cpp \
				RPN.cpp

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR		= objs
OBJS		= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEPS		= $(OBJS:.o=.d)

ifeq ($(MAKECMDGOALS), debug)
	FLAGS += -DDEBUG
endif

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(FLAGS) $(DEPFLAGS) $(INCLUDE) -o $@ -c $<

all: $(NAME)

debug: re

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./$(NAME) "7 7 * 7 -"
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	./$(NAME) "(1 + 1)"

-include $(DEPS)

.PHONY: all debug clean fclean re test
t: all