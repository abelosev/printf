NAME = libftprintf.a

# LFT = libft/libft.a

CC = cc

CF = -Wall -Werror -Wextra

INC = -Iinc

SRC = src/ft_printf.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CF) $(INC) -c $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

# $(LFT) :
# 	cd libft
# 	make re
# 	cd ..

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(NAME)
	rm -rf $(OBJ)

act : re
	$(CC) $(CF) $(INC) main.c -L. -lftprintf

re : fclean all

:PHONY : all clean fclean re