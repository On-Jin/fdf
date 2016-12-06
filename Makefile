# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 18:45:43 by ntoniolo          #+#    #+#              #
#    Updated: 2016/12/05 13:00:55 by ntoniolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

DIR_LFT = libft

DIR_MLXJI = libmlxji

FLAGS = -Wall -Werror -Wextra

SRC_FDF = srcs/alteration.c srcs/alteration2.c srcs/center.c srcs/color.c srcs/draw.c srcs/convert.c srcs/keyevent.c srcs/main.c srcs/recup.c

CC = gcc

OBJET_FDF = $(SRC_FDF:.c=.o)

.PHONY: all, clean, fclean, , re, $(NAME), lmlxji, lft, start, end

all: lmlxji start $(NAME) end

$(NAME): $(OBJET_FDF)
	$(CC) $(FLAGS) $(OBJET_FDF) -L./libft/ -lft -L./libmlxji/ -lmlxji -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -o $(NAME)

start:
	@echo "\033[4m\033[33mCreation de $(NAME)   ...\033[0m"

end:
	@echo "\033[4m\033[1m\033[32m>$(NAME) done.\033[0m"

srcs/%.o: srcs/%.c
	@echo "\033[34m$^ \033[0m-> \033[1m\033[37m$@\033[0m"
	@gcc $(FLAGS) -c $^ -o $@

lmlxji:
	@echo "\033[4m\033[33mCreation de libmlx.a  ...\033[0m"
	@(cd $(DIR_MLXJI) && $(MAKE))
	@echo "\033[4m\033[33mCreation de libft.a   ...\033[0m"
	@(cd $(DIR_LFT) && $(MAKE))

clean:
	@echo "\033[31mDelete .o of $(NAME)\033[0m"
	@/bin/rm -f $(OBJET_FDF)
	@(cd $(DIR_LFT) && make clean)
	@(cd $(DIR_MLXJI) && make clean)

fclean: clean
	@echo "\033[31mDelete .o and $(NAME)\033[0m"
	@/bin/rm -f $(NAME)
	@(cd $(DIR_LFT) && make fclean)
	@(cd $(DIR_MLXJI) && make fclean)

re: fclean all
