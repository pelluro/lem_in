# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipham <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/27 15:48:09 by mipham            #+#    #+#              #
#    Updated: 2018/03/23 13:41:17 by mipham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

_GREEN = $'\x1b[32m
_CYAN = $'\x1b[36m
_RED = $'\x1b[31m
_YELLOW = $'\x1b[33m
_PURPLE = $'\x1b[35m
_BLUE = $'\x1b[34m

LIB = include/libft

SRC = src/addroom.c\
        src/checkroom.c\
        src/createtab.c\
        src/displayresult.c\
        src/freemap.c\
        src/method.c\
        src/method2.c\
        src/main.c\
        src/solve.c\

INC = -I include

OBJ = $(SRC:.c=.o)

CC = gcc

LIBPATH = include/libft/libft.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBPATH)
	@echo "${_YELLlOW}lem_in generate${_END} ${_BLUE}[!${_END}]"

%.o: %.c include/lem_in.h
	$(CC) $(CFLAG) $(INC) -I $(LIB) -o $@ -c $<

clean:
		rm -f $(OBJ)
			make clean -C ./include/libft/
			@echo "${_CYAN}cleaning objects files${_END} ${_PURPLE}[!${_END}]"

fclean: clean
		rm -f $(NAME)
			make fclean -C ./include/libft/
			@echo "${_RED}delete $(NAME) ${_END}${_GREEN}[!${_END}]"

re: fclean all

.PHONY : all, re, clean, fclean
