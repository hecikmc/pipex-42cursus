NAME		= pipex

INC			= libft/

LIB			= $(INC)libft.a

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

SRC			=   main.c \
				subproces.c \
				check.c \
				pipex.c \
				splitpipex.c

OBJ_SRC		= $(SRC:.c=.o)

%.o: %.c
	@$(CC)$(FLAGS) -c $< -o $@

all:	$(LIB) $(NAME)

$(LIB):
	@make -C $(INC)

$(NAME)		: $(LIB) $(OBJ_SRC) 
	@$(CC) $(CFLAGS) $(LIB) $(OBJ_SRC) -o $(NAME)
	@echo "$(GREEN)$(NAME) -> program created! $(DEFAULT)"

clean		:
	@rm -f $(OBJ_SRC)
	@make -C $(INC) clean
	@echo "$(YELLOW)$(NAME) -> Object files deleted. "

fclean		: clean
	@rm -f $(NAME)
	@make -C $(INC) fclean
	@echo "$(RED)$(NAME) program -> All files deleted. "

re			: fclean all

.PHONY		:
	all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m