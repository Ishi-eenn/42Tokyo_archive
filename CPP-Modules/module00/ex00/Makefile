NAME		=	megaphone
CXX			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

SRC_DIR		=	srcs
SRC			=	megaphone.cpp

SRCS	= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR	= objs
OBJS    = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m


$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(SRCS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@ mkdir -p $(@D)
	$(CXX) $(FLAGS) -o $@ -c $<

all: $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

test: all
	@ echo "$(YELLOW) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~test~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$(RESET)"
	@ echo "$(GREEN) test1 $(RESET)"
	./$(NAME) "shhhhh... I think the students are asleep..."
	@ echo "$(GREEN) \n test2$(RESET)"
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@ echo "$(GREEN) \n test3$(RESET)"
	./$(NAME)
	@ echo "$(YELLOW) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ $(RESET)"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
