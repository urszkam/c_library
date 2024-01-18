NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_strncmp.c ft_atoi.c ft_strlen.c \
	ft_strlcat.c ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_bzero.c \
	ft_memset.c ft_memmove.c, ft_memcpy.c, ft_memset.c, ft_memcmp.c \
	ft_memchr.c ft_strndup.c ft_strnstr.c ft_strndup.c ft_calloc.cc

OBJS = $(SRCS:.c=.o)

HEADER = ./

%.c/%.o:
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME): {OBJ}
	ar csr $(NAME) $(OBJ)

all: $(NAME)

fclean: clean
	rm - f $(NAME)

clean:
	rm -f $(OBJ)

re: fclean all

.PHONY: clean fclean re all