NAME = push_swap

NAME_BONUS = checker

MAN = push_swap.c\
	  ps_1.c\
	  ft_utils_0.c\
	  ft_utils_1.c\
	  ft_utils_2.c\
	  ft_utils_3.c\
	  ft_utils_4.c\
	  ft_utils_5.c\
	  ft_utils_6.c\
	  ft_functions_1.c\
	  ft_functions_2.c\
	  ft_functions_3.c\
	  ft_atoi.c\
	  ft_split.c\

BONUS =	checker.c\
		ft_utils_bonus_0.c\
		ft_functions_bonus_1.c\
	  	ft_functions_bonus_2.c\
	  	ft_functions_bonus_3.c\
		ft_split.c\
	    ft_atoi.c\
		ft_get_next_line.c\
		ft_get_next_line_utils.c

OBJ = $(MAN: .c=.o)

OBJ_BONUS = $(BONUS: .c=.o)

CC = gcc
FLAGS = -Wall -Werror -Wextra
SAN = -g3 -fsanitize=address

RM = rm -f -r

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -c $(OBJ) $(MAN)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) #$(SAN)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) -c $(OBJ_BONUS) $(BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) #$(SAN)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)
	$(RM) *.dSYM

clean_bonus:
	$(RM) *.o

fclean_bonus: clean_bonus
	$(RM) $(NAME_BONUS)
	$(RM) *.dSYM

re: fclean all

re_bonus: fclean_bonus bonus

.PHONY: all clean bonus fclean re
