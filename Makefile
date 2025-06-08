CX = cc
CXFLAGS = -Wall -Wextra -Werror

SERVER_SRC = server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
SERVER = server

CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
CLIENT = client

SERVER_BONUS_SRC = server_bonus.c
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)
SERVER_BONUS = server_bonus

CLIENT_BONUS_SRC = client_bonus.c
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)
CLIENT_BONUS = client_bonus

LIBFT_DIR = includes/libft
PRINTF_DIR = includes/ft_printf
LIB_FT = $(LIBFT_DIR)/libft.a
LIB_PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIB_PRINTF):
	make -C includes/ft_printf

$(LIB_FT):
	make -C includes/libft

$(SERVER): $(SERVER_OBJ) $(LIB_PRINTF)
	$(CX) $(CXFLAGS) $(SERVER_OBJ) -o $(SERVER) $(LIB_PRINTF)

$(CLIENT): $(CLIENT_OBJ) $(LIB_PRINTF) $(LIB_FT)
	$(CX) $(CXFLAGS) $(CLIENT_OBJ) -o $(CLIENT) $(LIB_PRINTF) $(LIB_FT)

$(SERVER_BONUS): $(SERVER_BONUS_OBJ) $(LIB_PRINTF)
	$(CX) $(CXFLAGS) $(SERVER_BONUS_OBJ) -o $(SERVER_BONUS) $(LIB_PRINTF)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ) $(LIB_PRINTF) $(LIB_FT)
	$(CX) $(CXFLAGS) $(CLIENT_BONUS_OBJ) -o $(CLIENT_BONUS) $(LIB_PRINTF) $(LIB_FT)

%.o: %.c
	$(CX) $(CXFLAGS) -c $< -o $@

clean:
	rm -f $(SERVER_OBJ)
	rm -f $(CLIENT_OBJ)
	rm -f $(SERVER_BONUS_OBJ)
	rm -f $(CLIENT_BONUS_OBJ)
	make clean -C includes/ft_printf
	make clean -C includes/libft

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)
	rm -f $(SERVER_BONUS)
	rm -f $(CLIENT_BONUS)
	rm -f $(LIB_PRINTF)
	rm -f $(LIB_FT)

re: fclean all

.PHONY: all clean fclean re bonus
