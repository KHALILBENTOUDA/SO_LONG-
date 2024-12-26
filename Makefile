NAME = so_long
NAME_B = so_long_bonus

SRC = mandatory/so_long.c \
      mandatory/movement_handling.c \
      mandatory/libft_tools.c \
      mandatory/images_handling.c \
      mandatory/ft_split.c \
      mandatory/ft_error_tools.c \
      mandatory/checks_map.c \
      mandatory/get_map.c

SRC_B= bonus/so_long_bonus.c \
      bonus/movement_handling.c \
      bonus/libft_tools.c \
      bonus/images_handling.c \
      bonus/ft_split.c \
      bonus/ft_error_tools.c \
      bonus/checks_map.c \
      bonus/ft_itoa.c \
      bonus/enemy_move.c \
      bonus/get_map.c 

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

MFLAGS = -lmlx -framework OpenGL -framework Appkit
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OBJ) mandatory/so_long.h
	cc $(CFLAGS) $(MFLAGS) $(OBJ) -o $(NAME)

bonus:$(NAME_B)

$(NAME_B):$(OBJ_B) bonus/so_long_bonus.h
	cc $(CFLAGS) $(MFLAGS) $(OBJ_B) -o $(NAME_B)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_B)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re: fclean all bonus
