NAME	= fractol
CFLAGS	= -Wextra -Wall -Werror -g
CC		= gcc
LIBMLX	= ./MLX42/build
MLX_42	= MLX42/build/libmlx42.a
LIBFT	= ./libft/libft.a

HEADERS	:= -I $(LIBMLX)/include/MLX42
LIBS	:= $(MLX_42) -ldl -lglfw -pthread -lm fractol.h
SRCS	= main.c args_checker.c calc_coordenates.c ft_atod.c
OBJS	:= ${SRCS:.c=.o}
B_OBJS	:= ${B_SRC:.c=.o}

all: $(NAME)

$(MLX_42):
	@make -s -C $(LIBMLX)

$(LIBFT):
	@make -s -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(MLX_42) $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIBFT) -o $(NAME)

clean:
	@rm -rf *.o
	@make clean -s -C MLX42/build
	
fclean: clean
	@make fclean -sC libft
	@rm -rf *.o
	@rm -rf $(NAME)

bfclean:
	@rm -rf *.o
	@rm -rf $(BONUS)

re: fclean all

reb: bfclean bonus

.PHONY: all clean fclean re libmlx bonus bfclean