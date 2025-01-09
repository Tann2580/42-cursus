NAME = pipex

CFLAGS = -Wall -Werror -Wextra
SRCS = pipex.c\
		pipex_utils.c\
		libft/libft.a

$(NAME) :
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $@

all : $(NAME)

fclean : clean
		rm -f $(NAME)
		make fclean -C libft

clean : 
		rm -f $(NAME)
		make clean -C libft

re : fclean all

