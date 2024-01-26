NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_strncmp.c ft_atoi.c ft_strlen.c \
	ft_strlcat.c ft_strlcpy.c ft_strrchr.c ft_strnstr.c ft_bzero.c \
	ft_strchr.c ft_memset.c ft_memcpy.c ft_memset.c ft_memcmp.c \
	ft_memchr.c ft_strnstr.c ft_strdup.c ft_calloc.c ft_strtrim.c\
	ft_atoi.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_substr.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c

OBJS = $(SRCS:.c=.o)

HEADER = ./

.c.o:
	@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME): $(OBJS)
	@ar cr $(NAME) $(OBJS)
	@ranlib $(NAME)

all: $(NAME)

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f $(OBJS)

re: fclean all

tests:
	@$(CC) -o tests.out tests.c -L. -lft -I./ -lcunit
	@./tests.out
	@rm -f tests.out

bonus-tests:
	@$(CC) -o bonus_tests.out bonus_tests.c -L. -lft -I./ -lcunit
	@./bonus_tests.out
	@rm -f bonus_tests.out

.PHONY: clean fclean re all