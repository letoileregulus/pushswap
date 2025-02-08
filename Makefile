NAME = push_swap
CFLAGS = -Wall -Werror -Wextra
SRCS = main.c utils.c 
LIBFT=libft/libft.a

all: $(NAME)

$(NAME): $(SRCS)
	make -C ./libft -s
	cc 	$(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT)
clean:
	make -C ./libft clean -s

fclean: clean
	make -C ./libft fclean -s
	rm -f $(NAME)
		
re: fclean all

.PHONY: all clean fclean re