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
		( make -j$(nproc) -C libft > /dev/null 2>&1 ) & \
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


# === MLX SPINNER ===
define mlx_spinner
	@printf "$(YELLOW)🖼️  Compiling MiniLibX... $(RESET)"
	@bash -c ' \
		spin="/-\\|"; \
		i=0; \
		( make -j$(nproc) -C minilibx-linux > /dev/null 2>&1 ) & \
		pid=$$!; \
		while kill -0 $$pid 2>/dev/null; do \
			printf "\r🖼️  Compiling MiniLibX... $${spin:$$((i%4)):1} "; \
			i=$$((i+1)); \
			sleep 0.1; \
		done; \
		wait $$pid; \
		if [ $$? -eq 0 ]; then \
			printf "\r$(GREEN)🖼️  MiniLibX compiled successfully!    $(RESET)\n"; \
		else \
			printf "\r$(RED)✗ MiniLibX compilation failed!      $(RESET)\n"; \
			exit 1; \
		fi \
	'
endef


# === NOME E FILE ===
NAME = minirt
SRCSF = ./srcs/
RENDERERF = ./srcs/renderer/
COLLISION = ./srcs/renderer/collision_function/
PARSERF = ./srcs/parser/
CHECKERF = ./srcs/parser/checker/
CREATIONF = ./srcs/parser/objects_creation_funcs/
P_UTILSF = ./srcs/parser/parser_utils/
HANDLERSF = ./srcs/handlers/
INITF = ./srcs/init_funcs/
ERRORF = ./srcs/error_utils/
UTILSF = ./srcs/utils/
DEBUGF = ./srcs/debug_funcs/
SRC = \
	$(SRCSF)main.c \
	$(RENDERERF)generate_rays.c \
	$(RENDERERF)calculate_hit.c \
	$(RENDERERF)lighting.c \
	$(COLLISION)collision_circle.c \
	$(COLLISION)collision_cone.c \
	$(COLLISION)collision_cylinder.c \
	$(COLLISION)collision_plane.c \
	$(COLLISION)collision_sphere.c \
	$(CHECKERF)file_checker_funcs.c \
	$(CHECKERF)general_checker_funcs.c \
	$(CREATIONF)environment_funcs.c \
	$(CREATIONF)figures_funcs.c \
	$(CREATIONF)general_funcs.c \
	$(HANDLERSF)events_handlers.c \
	$(P_UTILSF)scene_utils.c \
	$(P_UTILSF)general_parser_utils.c \
	$(P_UTILSF)check_env_objs_utils.c \
	$(P_UTILSF)check_objs_utils.c \
	$(P_UTILSF)check_objs_params_utils_1.c \
	$(P_UTILSF)check_objs_params_utils_2.c \
	$(P_UTILSF)check_objs_params_utils_3.c \
	$(INITF)data_init.c \
	$(INITF)mlx_init.c \
	$(UTILSF)error_utils.c \
	$(UTILSF)free_utils.c \
	$(UTILSF)equation_utils.c \
	$(DEBUGF)debug_utils.c \
	$(DEBUGF)scene_debug.c
OBJ = $(SRC:.c=.o)

# === COMPILAZIONE ===

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -gdwarf-4 -flto -O0
INCLUDE = -Ilibft/header_files -I/usr/include -I./includes -I./minilibx-linux
LIBFLAGS = -Llibft -lft -lm
MLXFLAGS = -Imlx -Lmlx -lX11 -lXext

# === TARGET PRINCIPALI ===
all: $(NAME)

# Header viene mostrato prima di tutto se serve compilare
.header_shown: 
	@printf "$(CYAN)╔═════════════════════════════════════════════╗\n"
	@printf "║         $(MAGENTA)miniRT Build System v1.0$(CYAN)            ║\n"
	@printf "╚═════════════════════════════════════════════╝$(RESET)\n"
	@touch .header_shown

# Compila libft con spinner e poi miniRT
$(NAME): .header_shown libft/libft.a minilibx-linux/libmlx.a $(OBJ)
	@printf "\n$(GREEN)[✓] Source files compiled. Linking...$(RESET)\n"
	@$(CC) $(OBJ) -o $(NAME) libft/libft.a minilibx-linux/libmlx.a $(MLXFLAGS) $(LIBFLAGS) -lreadline -lncurses -lm -g -flto -O3
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

# === MLX COMPILATION CON SPINNER ===
minilibx-linux/libmlx.a: .header_shown
	$(call mlx_spinner)


# === COMPILAZIONE OGNI FILE .o con messaggio sulla stessa riga ===
%.o: %.c .header_shown
	@printf "\r\033[K$(YELLOW)🔨 Compiling $@...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) -g

# === PULIZIA ===
clean:
	@rm -f $(OBJ) .header_shown
	@make clean -C libft > /dev/null
	@make clean -C minilibx-linux > /dev/null
	@printf "$(RED)🧹 Cleaned object files.$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft > /dev/null
	@make clean -C minilibx-linux > /dev/null
	@printf "$(RED)🧹 Removed binary and libft objects.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
