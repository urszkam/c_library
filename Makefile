NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_strncmp.c ft_strlen.c ft_memmove.c \
	ft_strlcat.c ft_strlcpy.c ft_strrchr.c ft_bzero.c ft_split.c\
	ft_strchr.c ft_memset.c ft_memcpy.c ft_memcmp.c ft_itoa.c \
	ft_memchr.c ft_strnstr.c ft_strdup.c ft_calloc.c ft_strtrim.c\
	ft_atoi.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_substr.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \

BSRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstmap.c\
	ft_lstnew.c ft_lstsize.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c

BOBJS = ${BSRCS:.c=.o}

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
	@rm -f $(OBJS) $(BOBJS)

re: fclean all

bonus: $(NAME) $(BOBJS)
	@ar cr $(NAME) $(BOBJS)

tests:
	@$(CC) -o tests.out .tests.c -L. -lft -I./
	@touch endl.txt nbr.txt str.txt char.txt 
	@./tests.out
	@rm -f tests.out
	
memory_leaks:
	@$(CC) -o tests.out .tests.c -L. -lft -I./
	@touch endl.txt nbr.txt str.txt char.txt 
	valgrind --leak-check=full --show-leak-kinds=all ./tests.out
	@rm -f tests.out

tclean:
	@rm -f *.txt

bonus_tests:
	@$(CC) -o bonus_tests.out .bonus_tests.c -L. -lft -I./
	valgrind --leak-check=full --show-leak-kinds=all ./bonus_tests.out
	@rm -f bonus_tests.out

.PHONY: clean fclean re all tests bonus_tests
