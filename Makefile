NAME = push_swap

CFLAGS = -Werror -Wextra -Wall

CC = cc

OBJ_DIR = obj/

SRC_DIR = src/

HEADERS := -I ./include

SRC :=	main.c init.c list_utils.c list_utils2.c freedom.c sort.c \
		sort_utils.c a_swap.c a_push.c a_rotate.c a_rev_rotate.c \
		k_sort.c \

OBJ = $(SRC:.c=.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

LIBFT = ./libft/libft.a

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< -o $@ $(CFLAGS) $(HEADERS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	cd libft && make

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)

clean:
	cd libft && make clean
	rm -rf $(OBJ_DIR)

fclean: clean
	cd libft && make fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
