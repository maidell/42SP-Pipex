NAME =      pipex
HEADER =    -I ./includes
SRC_DIR =   ./sources
OBJ_DIR =	./objects
LIBFT 	=	./libft/libft.a
SRC_FILES =   	main.c pipex.c utils.c \
				parse.c

CC =		cc 

CFLAGS =	-Wall -Wextra -Werror

SRC =		$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ =		$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME) $(CFLAGS)

$(LIBFT):
	make -C ./libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	$(CC) $(HEADER) -c  $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
