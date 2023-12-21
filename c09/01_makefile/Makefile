CFLAGS = -Wall -Wextra -Werror
CFILES = ./src/ft_putchar.c ./src/ft_putstr.c ./src/ft_strcmp.c ./src/ft_strlen.c ./src/ft_swap.c
OFILES = ./src/ft_putchar.o ./src/ft_putstr.o ./src/ft_strcmp.o ./src/ft_strlen.o ./src/ft_swap.o
HEADER_DIR = includes
HEADER = ft.h

all: libft.a

%o: %c 
	gcc ${CFLAGS} -c -I $(HEADER_DIR) $< -o ${<:.c=.o}

libft.a: $(OFILES)
	ar rc libft.a $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY:  all clean fclean re
