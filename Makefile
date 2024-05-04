# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 17:33:49 by rnogueir          #+#    #+#              #
#    Updated: 2024/05/01 15:21:43 by rnogueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=fdf
SRC=main.c utils.c parsing.c polygon.c\
	render.c looping.c linealgebra.c\
	input.c projection.c color.c\
	transformations.c
CC=cc
LIBFT=libft
MLX_H=/usr/local/include/
LIBMLX=/usr/local/lib/libmlx.a
CFLAGS=-Wall -Wextra -Werror -O3
LFLAGS=-lmlx -lXext -lX11 -lm -L$(LIBMLX) -I$(MLX_H) -I$(LIBFT) -I.

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LFLAGS) $(LIBFT)/libft.a

$(LIBFT):
	make -C $(LIBFT)

clean:
	make -C $(LIBFT) clean

fclean:
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean $(NAME)

.PHONY: $(NAME) $(LIBFT) clean fclean re
