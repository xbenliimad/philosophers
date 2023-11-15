NAME= philo

SRC= handle_errors.c	handle_verification.c \
	handle_expand.c	handle_init.c	handle_launcher.c \
	handle_time.c	utils.c main.c \

OBJ= $(SRC:%.c=%.o)

FLAGS= -Wall -Wextra -Werror

all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all fclean clean re