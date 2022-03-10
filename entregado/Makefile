NAME = push_swap

MAN = push_swap.c\
	  ps_1.c\
	  ft_utils_0.c\
	  ft_utils_1.c\
	  ft_utils_2.c\
	  ft_utils_3.c\
	  ft_utils_4.c\
	  ft_utils_5.c\
	  ft_functions_1.c\
	  ft_functions_2.c\
	  ft_functions_3.c\
	  ft_atoi.c\
	  ft_split.c

OBJ = $(MAN: .c=.o)

CC = gcc
FLAGS = -Wall -Werror -Wextra
SAN = -g3 -fsanitize=address

RM = rm -f -r

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -c $(OBJ) $(MAN)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) #$(SAN)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME) 
	$(RM) push_swap.dSYM

re: fclean all

.PHONY: all clean fclean re
