CLIENT_NAME			=	client
CLIENT_DIR_SRC		=	./src/client
CLIENT_DIR_BUILD	=	./build/client
CLIENT_SOURCES		=	ft_atoi.c ft_isint.c main.c 
CLIENT_FUNCTIONS	=	$(subst .c,,$(CLIENT_SOURCES))
CLIENT_OBJECTS		=	$(addsuffix .o, $(addprefix $(CLIENT_DIR_BUILD)/, $(CLIENT_FUNCTIONS)))

SERVER_NAME			=	server
SERVER_DIR_SRC		=	./src/server
SERVER_DIR_BUILD	=	./build/server
SERVER_SOURCES		=	main.c 
SERVER_FUNCTIONS	=	$(subst .c,,$(SERVER_SOURCES))
SERVER_OBJECTS		=	$(addsuffix .o, $(addprefix $(SERVER_DIR_BUILD)/, $(SERVER_FUNCTIONS)))

FT_PRINTF	=	./lib/ft_printf
FLAGS		=	-Wall -Wextra -Werror -fsanitize=address

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJECTS)
	@make -C $(FT_PRINTF)
	@cc $(CLIENT_OBJECTS) $(FLAGS) -L $(FT_PRINTF) -lftprintf -o $@

$(SERVER_NAME): $(SERVER_OBJECTS)
	@make -C $(FT_PRINTF)
	@cc $(SERVER_OBJECTS) $(FLAGS) -L $(FT_PRINTF) -lftprintf -o $@

$(CLIENT_DIR_BUILD)/%.o: $(CLIENT_DIR_SRC)/%.c | $(CLIENT_DIR_BUILD)
	@cc $(FLAGS) -I $(FT_PRINTF) -c $^ -o $@

$(SERVER_DIR_BUILD)/%.o: $(SERVER_DIR_SRC)/%.c | $(SERVER_DIR_BUILD)
	@cc $(FLAGS) -I $(FT_PRINTF) -c $^ -o $@

$(CLIENT_DIR_BUILD):
	@mkdir -p $@

$(SERVER_DIR_BUILD):
	@mkdir -p $@

clean:
	make clean -C $(FT_PRINTF)
	rm -rf $(CLIENT_DIR_BUILD)
	rm -rf $(SERVER_DIR_BUILD)

fclean: clean
	make fclean -C $(FT_PRINTF)
	rm -f $(CLIENT_NAME)
	rm -f $(SERVER_NAME)

re: fclean all
	make re -C $(FT_PRINTF)
