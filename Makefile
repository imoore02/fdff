NAME = ex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = drawline.c

all: $(NAME)
	
$(NAME): $(SRC)
	@echo "compiling fdf..."
	@$(CC) $(SRC) -L mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "done!"

%.o: %.c
	@echo "generating fdf objects..."
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	@echo "deleting objects..."
	@rm -f $(SRC)
	@echo "done!"

fclean:
	@echo "deleting objects..."
	@rm -f $(SRC)
	@echo "deleting executable..."
	@rm -f $(MAIN)
	@echo "done!"

re: fclean all

.PHONY: clean fclean re bonus