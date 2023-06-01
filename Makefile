NAME = libftprintf.a

SRC = 	ft_printf.c\
		utils.c\

INCLUDE = libftprintf.h

OBJ = $(SRC:.c=.o)

RM = rm -f

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all