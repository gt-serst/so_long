# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 17:01:35 by gt-serst          #+#    #+#              #
#    Updated: 2023/05/26 17:49:17 by geraudtsers      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= so_long

CC					= gcc

CFLAGS				= -Wall -Wextra -Werror -g3 -fsanitize=address

RM					= rm -rf

SRCS				= main.c \
					  parsing.c \
					  map_cleaning.c \
					  parsing_utils.c \
					  flood_fill.c \
					  mlx_init.c \
					  mlx_graphic.c \
					  mlx_assets.c \
					  game.c

OBJS				= $(addprefix srcs/, $(SRCS:.c=.o))

# LIBFT
LIBFT_PATH			= ./libft

LIBFT				= $(LIBFT_PATH)/libft.a

# MLX
MLX_L				= -Lmlx_linux -lmlx_Linux -L /usr/local/lib
MLX_M				= -g -L /usr/X11/lib
MLX_INCLUDES_L		= -I /usr/local/include -Imlx_linux
MLX_INCLUDES_M		= -I /usr/X11/include
MLX_FLAGS_L			= -Imlx_linux -lXext -lX11 -lm -lz
MLX_FLAGS_M			= -lX11 -lmlx -lXext

.c.o:
					$(CC) -c -I ./includes -Imlx -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
					$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit  $(OBJS) $(LIBFT) -o $(NAME)

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

ecole: $(LIBFT) $(OBJS)
					$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit  $(OBJS) $(LIBFT) -o $(NAME)

local: $(LIBFT) $(OBJS)
					$(CC) $(CFLAGS) -g -L /usr/X11/lib -lmlx -I /usr/X11/include -lX11 -lmlx -lXext $(OBJS) $(LIBFT) -o $(NAME)
