# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 18:45:43 by ntoniolo          #+#    #+#              #
#    Updated: 2016/12/05 13:03:31 by ntoniolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmlxji.a

FLAGS = -Wall -Werror -Wextra

SRC = srcs/mlxji_clear_img.c srcs/mlxji_draw_line.c srcs/mlxji_hsv_to_rgb.c srcs/mlxji_new_img.c srcs/mlxji_put_pixel.c

OBJET = $(SRC:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJET)
	@ar rc $(NAME) $(OBJET) && ranlib $(NAME)
	@echo "\033[4m\033[1m\033[32m>$(NAME) done.\033[0m"

%.o: %.c
	@echo "\033[34m$^ \033[0m-> \033[1m\033[37m$@\033[0m"
	@gcc $(FLAGS) -o $@ -c $^

clean:
	@echo "\033[31mDelete .o of $(NAME)\033[0m"
	@/bin/rm -f $(OBJET)

fclean: clean
	@echo "\033[31mDelete .o and $(NAME)\033[0m"
	@/bin/rm -f $(NAME)

re: fclean all
