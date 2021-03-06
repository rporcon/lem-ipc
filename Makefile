LEMIPC_NAME = lemipc

MAP_NAME = map

SRCS_DIR = ./src/

INCLUDE_DIR = ./include

LFT_NAME = libft.a

LFT_DIR = ./libft

LEMIPC_SRC_FILE = dbg.c args.c sig.c msg.c player_move.c players_data.c \
					players_played.c enemy.c cells_val.c enemy_chr.c \
					enemy_moveto.c shm_mapinit.c shm_map.c lemipc.c

LEMIPC_SRC = $(addprefix $(SRCS_DIR), $(LEMIPC_SRC_FILE))

LEMIPC_OBJ = $(LEMIPC_SRC:%.c=%.o)

MAP_SRC_FILE = map_args.c map_players.c map_gamelaunch.c map_print.c

MAP_SRC = $(addprefix $(SRCS_DIR), $(MAP_SRC_FILE))

MAP_OBJ = $(MAP_SRC:%.c=%.o)

CC = @gcc

LFLAGS = -lft

IFLAGS = -I$(INCLUDE_DIR)

CFLAGS = -Wall -Werror -Wextra $(IFLAGS)

all: $(LEMIPC_NAME) $(MAP_NAME)

$(LEMIPC_NAME): $(LEMIPC_OBJ)
	@make --no-print-directory -C $(LFT_DIR)
	$(CC) -o $(LEMIPC_NAME) $(LEMIPC_OBJ) $(LFLAGS) -L$(LFT_DIR) \
		$(LFT_DIR)/$(LFT_NAME)

$(MAP_NAME): $(MAP_OBJ)
	$(CC) -o $(MAP_NAME) $(MAP_OBJ) $(LFLAGS) -L$(LFT_DIR) \
		$(LFT_DIR)/$(LFT_NAME)

clean:
	@rm -f $(LEMIPC_OBJ) $(MAP_OBJ)

fclean: clean
	@rm -f $(LEMIPC_NAME) $(MAP_NAME)

re: fclean all

debug: CFLAGS += -g -D _DEBUG
debug: re

.PHONY: clean fclean re
