# === COLORI ===
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
RESET=\033[0m

# === SPINNER FUNCTION ===
define spinner
	@printf "$(YELLOW)📦 Compiling libft... $(RESET)"
	@bash -c ' \
		spin="/-\\|"; \
		i=0; \
		( make -C libft > /dev/null 2>&1 ) & \
		pid=$$!; \
		while kill -0 $$pid 2>/dev/null; do \
			printf "\r📦 Compiling libft... $${spin:$$((i%4)):1} "; \
			i=$$((i+1)); \
			sleep 0.1; \
		done; \
		wait $$pid; \
		if [ $$? -eq 0 ]; then \
			printf "\r$(GREEN)📦 libft compiled successfully!     $(RESET)\n"; \
		else \
			printf "\r$(RED)✗ libft compilation failed!        $(RESET)\n"; \
			exit 1; \
		fi \
	'
endef

# === NOME E FILE ===
NAME = minirt
PARSERF = ./srcs/parser/
CREATIONF = ./srcs/parser/objects_creation_funcs/
P_UTILSF = ./srcs/parser/parser_utils/
INITF = ./srcs/init_funcs/
ERRORF = ./srcs/error_utils/
UTILSF = ./srcs/utils/
DEBUGF = ./srcs/debug_funcs/
SRC = \
	$(PARSERF)check_file.c \
	$(CREATIONF)environment_funcs.c \
	$(CREATIONF)figures_funcs.c \
	$(CREATIONF)general_funcs.c \
	$(P_UTILSF)scene_utils.c \
	$(INITF)data_init.c \
	$(UTILSF)error_utils.c \
	$(UTILSF)free_utils.c \
	$(DEBUGF)debug_utils.c \
	$(DEBUGF)scene_debug.c
OBJ = $(SRC:.c=.o)

# === COMPILAZIONE ===
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -gdwarf-4
INCLUDE = -Ilibft/header_files -I/usr/include -I./includes
LIBFLAGS = -Llibft -lft -lm

# === TARGET PRINCIPALI ===
all: $(NAME)

# Header viene mostrato prima di tutto se serve compilare
.header_shown: 
	@printf "$(CYAN)╔═════════════════════════════════════════════╗\n"
	@printf "║         $(MAGENTA)miniRT Build System v1.0$(CYAN)            ║\n"
	@printf "╚═════════════════════════════════════════════╝$(RESET)\n"
	@touch .header_shown

# Compila libft con spinner e poi miniRT
$(NAME): .header_shown libft/libft.a $(OBJ)
	@printf "\n$(GREEN)[✓] Source files compiled. Linking...$(RESET)\n"
	@$(CC) $(OBJ) -o $(NAME) libft/libft.a -lreadline -lncurses -lm -g
	@printf "$(GREEN)✔ Compilation completed successfully!$(RESET)\n"
	@printf "$(BLUE)"
	@printf "      _----------_,\n"
	@printf "    ,\"__         _-:,\n" 
	@printf "   /    \"\"--_--\"\"...:\\\\\n"
	@printf "  /         |.........\\\\\n"
	@printf " /          |..........\\\\\n"
	@printf "/,         _'_........./:   $(MAGENTA)MiniRT Ready!$(BLUE)\n"
	@printf "! -,    _-\"   \"-_... ,;;:\n"
	@printf "\\\\   -_-\"         \"-_/;;;;\n"
	@printf " \\\\   \\\\             /;;;;'\n"
	@printf "  \\\\   \\\\           /;;;;\n"
	@printf "   '.  \\\\         /;;;'\n"
	@printf "     \"-_\\\\_______/;;'\n"
	@printf "$(RESET)"
# === LIBFT COMPILATION CON SPINNER ===
libft/libft.a: .header_shown
	$(call spinner)

# === COMPILAZIONE OGNI FILE .o con messaggio sulla stessa riga ===
%.o: %.c .header_shown
	@printf "\r\033[K$(YELLOW)🔨 Compiling $@...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

# === PULIZIA ===
clean:
	@rm -f $(OBJ) .header_shown
	@make clean -C libft > /dev/null
	@printf "$(RED)🧹 Cleaned object files.$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft > /dev/null
	@printf "$(RED)🧹 Removed binary and libft objects.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
