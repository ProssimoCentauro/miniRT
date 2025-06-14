# Color macros (bold)
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
RESET=\033[0m
# -------------------

NAME = minirt


PARSERF = ./srcs/parser/
CREATIONF = ./srcs/parser/objects_creation_funcs/
P_UTILSF = ./srcs/parser/parser_utils/

INITF = ./srcs/init_funcs/
ERRORF = ./srcs/error_utils/
UTILSF = ./srcs/utils/
DEBUGF = ./srcs/debug_funcs/
#CHECKF = ./srcs/check_objs/check

SRC = $(PARSERF)check_file.c $(CREATIONF)environment_funcs.c $(CREATIONF)figures_funcs.c $(CREATIONF)general_funcs.c $(P_UTILSF)scene_utils.c $(INITF)data_init.c $(UTILSF)error_utils.c $(UTILSF)free_utils.c $(DEBUGF)debug_utils.c
OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -gdwarf-4

INCLUDE = -Ilibft/header_files -I/usr/include -I./includes

LIBFLAGS = -Llibft -lft -L/usr/lib -lm

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(OBJ) $(LIBFLAGS) -o $(NAME) -lreadline -lncurses -g
	@echo "$(GREEN)compilation done :)$(RESET)"

%.o:%.c
	@echo "$(YELLOW)compiling $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean:
	rm -f $(OBJ) $(NAME)
	make fclean -C libft

re: fclean $(NAME)

.PHONY: all clean fclean re
