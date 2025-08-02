NAME = libftprintf.a

CC = cc

CF = -Wall -Werror -Wextra

INC = -Iinc -Ilibft

SRC = src/ft_printf.c \
		src/ft_printf_utils.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CF) $(INC) -c $< -o $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean :
	rm -rf $(NAME)
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) fclean

act : re
	$(CC) $(CF) $(INC) main.c -L. -lftprintf -Llibft -lft

re : fclean all

:PHONY : all clean fclean re