NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SUB = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c /
	ft_toupper.c ft_tolower.c ft_strncmp.c ft_atoi.c ft_strlen.c /
	ft_strlcat.c ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_bzero.c /
	*ft_memset.c
OBJ = ${SUB:.c=.o}
HEADER = "./"

%.c:%.o:
	

$(NAME): {OBJ}

all: $(NAME)

fclean: clean
	rm - f $(NAME)

clean:
	rm -f $(OBJ)

re: clean fclean all