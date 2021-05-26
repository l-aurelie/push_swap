NAME        =    push_swap
SRC         =	$(addprefix src/, push_swap.c list_utils.c move.c move_a.c move_b.c find_pivot.c quick_sort.c sort.c opti.c lib_utils.c sort_utils2.c sort_utils1.c)
OBJ           =    $(SRC:.c=.o)
CC            =    gcc
HEADER        =    -Iheader
CFLAGS        =    -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(HEADER) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:    all clean fclean re
