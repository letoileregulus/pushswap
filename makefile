NAME = push_swap
CFLAGS = -Wall -Werror -Wextra
SRCS = main.c utils.c 
LIBFT=libft/libft.a

all: $(NAME)

$(NAME): $(SRCS)
	make -C ./libft -s
	cc -o $(NAME) $(SRCS) $(LIBFT)
clean:
	rm -f $(OBJS) 
# Bu gereksiz ^

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#Düzenleeeee