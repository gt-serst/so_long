# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 17:01:35 by gt-serst          #+#    #+#              #
#    Updated: 2023/06/14 00:11:43 by gt-serst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= so_long

CC					= gcc

CFLAGS				= -Wall -Wextra -Werror -g3 -fsanitize=address

RM					= rm -rf

SRCS				= main.c \
					parsing.c \
					cleaning.c \
					parsing_utils.c \
					flood_fill.c \
					flood_fill_utils.c \
					init.c \
					mlx_graphic.c \
					rendering.c \
					game.c \
					motion.c \
					mechanics.c

OBJS				= $(addprefix srcs/, $(SRCS:.c=.o))

# LIBFT
LIBFT_PATH			= ./libft

LIBFT				= $(LIBFT_PATH)/libft.a

# MLX
MLX_L				= -Lmlx_linux -lmlx_Linux -L /usr/local/lib
MLX_M				= -L /usr/local/lib
MLX_INCLUDES_L		= -I /usr/local/include -Imlx_linux
MLX_INCLUDES_M		= -I /usr/local/include -Imlx
MLX_FLAGS_L			= -Imlx_linux -lXext -lX11 -lm -lz
MLX_FLAGS_M			= -lmlx -framework OpenGL -framework AppKit

.c.o:
					$(CC) -c -I ./includes $(MLX_INCLUDES_L) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
					$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_L) $(MLX_FLAGS_L) -o $(NAME)

$(LIBFT):
					make -C $(LIBFT_PATH) all

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJS)

fclean: clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
