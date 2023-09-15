NAME= philo

SRC= ./src/main.c \
./src/parsing.c \
./src/ft_atoi.c \

OBJ= $(SRC:%.c=%.o)

INCLUDES= -I./includes

FLAGS= -Wall -Wextra -Werror $(INCLUDES) -fsanitize=address

all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all fclean clean re