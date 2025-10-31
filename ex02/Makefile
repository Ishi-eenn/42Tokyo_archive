NAME		=	PmergeMe
CXX			=	c++

INCLUDE		=	-I./includes
FLAGS		=	-std=c++98 -Wall -Wextra -Werror -pedantic
DEPFLAGS	=	-MMD -MP
RM			=	rm -rf

SRC_DIR		=	srcs
SRC			=	main.cpp \
				PmergeMe.cpp

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR		= objs
OBJS		= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEPS		= $(OBJS:.o=.d)

ifeq ($(MAKECMDGOALS), debug)
	FLAGS += -DDEBUG
endif

ifeq ($(MAKECMDGOALS), vs)
	FLAGS += -DVS
endif

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(FLAGS) $(DEPFLAGS) $(INCLUDE) -o $@ -c $<

all: $(NAME)

debug: re

vs: re

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all debug vs clean fclean re
