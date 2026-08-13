NAME		=	a.out
CXX			=	c++
INCLUDE	=	-I./includes
FLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

SRC_DIR	=	srcs
SRC			=	main.cpp \
					Fixed.cpp
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR	= objs
OBJS		= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

ifeq ($(MAKECMDGOALS), test)
  FLAGS += -DTEST
endif

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(INCLUDE) $(SRCS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@ mkdir -p $(@D)
	$(CXX) $(FLAGS) $(INCLUDE) -o $@ -c $<

all		: $(NAME) $(OBJS)

%.o		: %.cpp
	$(CXX) $(FLAGS) $(INCLUDE) -c $< -o $@

diff	: all
	@ ./$(NAME) 1> diff/myOutput 2> diff/myConstractor
	@ bash diff/diff.sh

clean	:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) diff/myOutput
	$(RM) diff/myConstractor

re		: fclean all

test	: re

.PHONY: all clean fclean re test diff
