# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 17:01:35 by gt-serst          #+#    #+#              #
#    Updated: 2023/06/07 11:23:24 by gt-serst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= so_long

CC					= gcc

CFLAGS				= -Wall -Wextra -Werror

RM					= rm -rf

# SRCS
SRCS				= $(addprefix $(SRCS_DIR),\
					main.c \
					parsing.c \
					cleaning.c \
					parsing_utils.c \
					flood_fill.c \
					flood_fill_utils.c \
					display_init.c \
					mlx_graphic.c \
					mlx_assets.c \
					game_init.c \
					motion.c \
					mechanics.c)

SRCS_DIR			= ./srcs/

# LIBFT
LIBFT_DIR			= ./libft

LIBFT				= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT)
					$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
					make -C $(LIBFT_DIR) all

clean:
					make -C $(LIBFT_DIR) clean

fclean: clean
					make -C $(LIBFT_DIR) fclean
					$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
