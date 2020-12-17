NAME = fillit

FLAGS = -Wextra -Wall -Werror

CC		= gcc

SRC =	fillit.c \
		ft_load_tetriminos.c \
		tetri_maps.c \
		tetri_map_filler.c


$(NAME):
	make -C libft/ fclean && make -C libft/
	$(CC) $(FLAGS) -o fillit $(SRC) -L libft/ -lft

all: $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re lib