NAME = minirt


PARSERF = ./srcs/parser/
INITF = ./srcs/init_funcs/
ERRORF = ./srcs/error_utils/
UTILSF = ./srcs/utils/

#CHECKF = ./srcs/check_objs/check

SRC = $(PARSERF)check_file.c $(INITF)data_init.c $(UTILSF)error_utils.c $(UTILSF)free_utils.c
OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -gdwarf-4

INCLUDE = -Ilibft/header_files -I/usr/include -I./includes

LIBFLAGS = -Llibft -lft -L/usr/lib -lm

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(OBJ) $(LIBFLAGS) -o $(NAME) -lreadline -lncurses -g
	@echo "compilation done :)"

%.o:%.c
	@echo "compiling $@"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean:
	rm -f $(OBJ) $(NAME)
	make fclean -C libft

re: fclean $(NAME)

.PHONY: all clean fclean re
