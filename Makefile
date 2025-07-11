NAME = chess
FLAGS = -Wall -Wextra -Werror
OPTION = -MMD -c -I.
# Paths
LIBFT_PATH = lib/Libft
MINILIBX_PATH = mlx_linux

INCLUDE = Makefile $(LIBFT_PATH)/libft.h $(LIBFT_PATH)/libft.a \
	 $(MINILIBX_PATH)/libmlx_Linux.a src/chess.h

# Library files
LIBFT = $(LIBFT_PATH)/libft.a
MINILIBX = $(MINILIBX_PATH)/libmlx_Linux.a

# Source and object files
SRC = src/main.c \
	src/hooks.c \
	src/prints.c \
	src/print_board.c \
	src/selection.c \
	textures/rook.c \
	textures/horse.c \
	textures/bishop.c \
	textures/queen.c \
	textures/king.c \
	textures/pawn.c \
	textures/mouse.c

OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

# Compile the final executable
all: $(NAME)

-include $(DEP)

# Rebuild Libft if any object file changes
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_PATH)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(OBJ) $(FLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT) $(MINILIBX) -o $(NAME)

# Compile object files and generate .d files for dependencies
%.o: %.c $(INCLUDE)
	cc $(FLAGS) $(OPTION) $< -o $@

# Include the generated dependency files

# Clean object and dependency files
clean:
	/bin/rm -f $(OBJ) $(DEP)
	$(MAKE) -C $(LIBFT_PATH) clean

# Full clean
fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(MINILIBX_PATH) clean

# Rebuild everything
re: fclean all

.PHONY: all, clean, fclean, re
