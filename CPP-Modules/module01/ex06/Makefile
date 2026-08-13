NAME		=	harlFilter
CXX			=	c++
INCLUDE		=	-I./includes
FLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

SRC_DIR		=	srcs
SRC			=	main.cpp \
				Harl.cpp

SRCS	= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR	= objs
OBJS	= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(INCLUDE) $(SRCS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@ mkdir -p $(@D)
	$(CXX) $(FLAGS) $(INCLUDE) -o $@ -c $<

all: $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
