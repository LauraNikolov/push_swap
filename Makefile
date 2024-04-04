COMPIL = cc
NAME = push_swap
FLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN = \033[0;32m
NC = \033[0m

$(NAME): $(OBJS)
	@echo "$(GREEN)Compilation: $(NC)"
	$(COMPIL) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(GREEN)Compiling $<$(NC)"
	$(COMPIL) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
