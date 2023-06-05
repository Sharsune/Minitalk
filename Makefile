NAME = minitalk

CLIENT = client

SERVER = server

LIBFT = libft/libft.a

SRC_CLIENT = client.c

SRC_SERVER = server.c

WWW = -Wall -Wextra -Werror

all: $(LIBFT) $(CLIENT) $(SERVER) 

$(NAME): all

$(LIBFT):
	make -C libft

$(CLIENT): $(SRC_CLIENT) $(LIBFT)
	cc $(WWW) $(SRC_CLIENT) -L libft/ -lft -o $(CLIENT)

$(SERVER): $(SRC_SERVER) $(LIBFT)
	cc $(WWW) $(SRC_SERVER) -L libft/ -lft -o $(SERVER)

clean:
	rm -f $(OSRC)
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(CLIENT) $(SERVER)
	rm -f $(LIBFT)

%.o: %.c
	cc $(WWW)  -g -c -o  $@ $^

re: fclean all

.PHONY: all clean fclean re