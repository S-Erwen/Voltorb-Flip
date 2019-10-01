NAME 	= 	./bin/voltorb.exe

SRCS 	= 	main.c \
			./src/interface.c \
			./src/volt.c \
			./src/map/map.c \
			./src/algo.c \
			./include/libft/ft_putstr.c \
			./include/libft/ft_putnbr.c \
			./include/libft/ft_putstr_fd.c \
			./include/libft/ft_strlen.c \
			./include/libft/strchrstr.c \
			./include/libft/ft_putchar.c \
			./include/libft/ft_strsplit.c \
			./include/libft/ft_putchar_fd.c \
			./include/libft/ft_strstr.c \
			./include/libft/ft_itoa.c \

HEADER 	= volt.h
OBJS 	= ${SRCS:.c=.o}

.c.o: $(HEADER)
		gcc -Wall -Wextra -Werror -I include -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
		gcc $(OBJS) -o $(NAME)

all : $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
