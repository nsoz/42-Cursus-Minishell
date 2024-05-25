PROGRAMNAME = minishell

CC = gcc -Wall -Werror -Wextra -lreadline

SRC = controller_before_pars.c mini_shell.c parser_next.c parser.c error_check.c

OBJ = controller_before_pars.o mini_shell.o parser_next.o parser.o error_check.o

LIBFTA = libft/libft.a

all: $(PROGRAMNAME)

$(PROGRAMNAME): $(SRC)
	make -C libft/
	$(CC) $(SRC) $(LIBFTA) -o $(PROGRAMNAME)

clean:
	make clean -C libft/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -rf $(PROGRAMNAME)

re: fclean all