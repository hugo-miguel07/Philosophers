NAME = philo
SRCS = philosophers.c utils.c routine.c \
		finishsim.c time.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g

INCLUDES = -I.

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@echo 'objetos Limpos'

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus