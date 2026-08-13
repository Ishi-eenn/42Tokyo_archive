NAME			=	a.out
CXX				=	c++
INCLUDE			=	-I./includes
FLAGS			=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -rf

SRC_DIR			=	srcs
SRC				=	Animal.cpp \
					Cat.cpp \
					Dog.cpp \
					main.cpp \
					WrongAnimal.cpp \
					WrongCat.cpp

SRCS			= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR		= objs
OBJS			= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

ifeq ($(MAKECMDGOALS), debug)
	FLAGS += -DDEBUG
endif

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(INCLUDE) $(SRCS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@ mkdir -p $(@D)
	$(CXX) $(FLAGS) $(INCLUDE) -o $@ -c $<

all: $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(FLAGS) $(INCLUDE) -c $< -o $@

test: all
	./a.out

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: re

.PHONY: all test clean fclean re debug
