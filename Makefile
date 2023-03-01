NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
MFLAGS = -framework OpenGL -framework AppKit -L./mlx -lmlx

MLX = ./mlx/libmlx.a
SRCS = test.c utils.c

$(NAME): $(SRCS) $(MLX)
		@gcc $(FLAGS) $(MFLAGS) $(SRCS) -o $(NAME)

all: $(MLX) $(NAME)

$(MLX):
	@make -C ./mlx

clean:
	@rm -rf ./mlx/*.o

fclean: clean
	@rm -rf ./mlx/*.a
	@rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
