NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
MFLAGS = -framework OpenGL -framework AppKit -L../mlx -lmlx

MLX = ../mlx/libmlx.a
GNL = ../gnl/get_next_line.c ../gnl/get_next_line_utils.c
SRCS = so_long.c utils.c draw_functions.c libft.c map_utils.c move_functions.c

$(NAME): $(SRCS) $(MLX) $(GNL)
		@gcc $(FLAGS) $(MFLAGS) $(GNL) $(SRCS) -o $(NAME)

all: $(MLX) $(GNL) $(NAME)

$(MLX):
	@make -C ../mlx

sclean:
	@rm -rf $(NAME)

clean:
	@rm -rf ../mlx/*.o

fclean: clean
	@rm -rf ../mlx/*.a
	@rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
