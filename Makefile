NAME = philo
SRCS = philosophers.c utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo 'objetos Limpos'

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus