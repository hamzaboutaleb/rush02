SRCS = main.c file.c number.c string.c array.c tokenizer.c
OBJS = $(SRCS:.c=.o)
NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re