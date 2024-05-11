# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 17:33:49 by rnogueir          #+#    #+#              #
#    Updated: 2024/05/11 19:01:35 by rnogueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=fdf
SRC=main.c utils.c parsing.c polygon.c\
	render.c looping.c linealgebra.c\
	input.c projection.c color.c\
	transformations.c input_utils.c\
	render_utils.c
BONUS_SRC=main_bonus.c utils.c parsing.c polygon.c\
	render.c looping.c linealgebra.c\
	input_bonus.c projection.c color.c\
	transformations.c input_utils.c\
	render_utils.c
CC=cc
LIBFT=./libft/libft.a
MLX_H=/usr/local/include/
LIBMLX=/usr/local/lib/libmlx.a
CFLAGS=-Wall -Wextra -Werror -O3
LFLAGS=-lmlx -lXext -lX11 -lm -L$(LIBMLX) -I$(MLX_H) -Ilibft -I.

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LFLAGS) $(LIBFT)

$(LIBFT):
	make -C libft 

bonus: $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_SRC) $(LFLAGS) $(LIBFT)

clean:
	make -C libft clean

fclean:
	rm -f $(NAME)
	make -C libft fclean

re: fclean $(NAME)

.PHONY: clean fclean re
