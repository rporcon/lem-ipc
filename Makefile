NAME = lemipc

SRCS_DIR = ./src/

INCLUDE_DIR = ./include

LFT_NAME = libft.a

LFT_DIR = ./libft

SRC_FILE = args.c shm.c lemipc.c

SRC = $(addprefix $(SRCS_DIR), $(SRC_FILE))

OBJ = $(SRC:%.c=%.o)

CC = @gcc

LFLAGS = -lft

IFLAGS = -I$(INCLUDE_DIR)

CFLAGS = -Wall -Werror -Wextra $(IFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	@make --no-print-directory -C $(LFT_DIR)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS) -L$(LFT_DIR) $(LFT_DIR)/$(LFT_NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g -D _DEBUG
debug: re

.PHONY: clean fclean re
