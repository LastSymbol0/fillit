NAME = fillit

SRC = fillit.c \
	fillit_help.c \
	fillit_read.c \
	fillit_solve.c \
	fillit_struct.c \
	fillit_valid.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_strlen.c \
	ft_strnew.c \
	get_next_line.c

	
OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

INCLUDES = fillit.h



all: $(NAME)

$(NAME): 
	@gcc $(FLAGS) -c $(SRC) -I $(INCLUDES)
	@gcc -o $(NAME) $(OBJ) $(FLAGS)
	@echo "\x1b[32m Success build"

clean:
	@rm -f $(OBJ)
	@echo "\x1b[32m Success clean"

fclean: clean
	@rm -f $(NAME)

re: fclean all
