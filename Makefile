# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 17:01:35 by gt-serst          #+#    #+#              #
#    Updated: 2023/05/12 17:59:02 by gt-serst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= so_long

CC					= gcc

CFLAGS				= -Wall -Wextra -Werror

RM					= rm -rf

SRCS				= main.c \
					  parsing.c

OBJS				= $(addprefix srcs/, $(SRCS:.c=.o))

LIBFT_PATH			= ./libft

LIBFT				= $(LIBFT_PATH)/libft.a

.c.o:
					$(CC) $(CFLAGS) -c -I ./includes $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
					$(CC) -o $(NAME) $(OBJS) $(LIBFT)

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
