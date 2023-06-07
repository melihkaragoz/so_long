NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra
MFLAGS = -framework OpenGL -framework AppKit -L../mlx -lmlx

MLX = ../mlx/libmlx.a
LIBFT = ../libft/
GNL = ../gnl/get_next_line.c ../gnl/get_next_line_utils.c
SRCS = so_long.c utils.c map_utils.c draw_functions.c move_functions.c error_checker.c extended_utils.c valid_path.c find.c

$(NAME): $(SRCS) $(MLX) $(GNL) $(LIBFT)
		@gcc $(FLAGS) $(MFLAGS) $(GNL) ../libft/libft.a $(SRCS) -o $(NAME)

all: $(MLX) $(GNL) $(LIBFT) $(NAME)

$(MLX):
	make -C ../libft
	@make -C ../mlx

sclean:
	@rm -rf $(NAME)

clean:
	@rm -rf ../mlx/*.o

fclean: clean
	@rm -rf ../mlx/*.a
	@rm -rf ../libft/*.o
	@rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
