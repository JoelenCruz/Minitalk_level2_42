# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcruz-da <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 19:26:09 by jcruz-da          #+#    #+#              #
#    Updated: 2023/02/11 19:28:29 by jcruz-da         ###   ########.fr        #
#                                                                              #
# *************************************************************************** #

NAME = minitalk.a

NAMELIBFT = libft/libft.a

LIBDIR = ./include/

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(LIBDIR)

SRC_C = src/client.c
SRC_S = src/server.c

#SRC_C_BONUS = src/client_bonus.c
#SRC_S_BONUS = src/server_bonus.c

all: $(NAME)

$(NAMELIBFT):
	make all -C ./libft

$(NAME): $(NAMELIBFT)
	$(CC) $(CFLAGS) $(SRC_C) $(NAMELIBFT) -o client
	$(CC) $(CFLAGS) $(SRC_S) $(NAMELIBFT) -o server

#bonus: $(NAMELIBFT)
#        $(CC) $(CFLAGS) $(SRC_C_BONUS) $(NAMELIBFT) -o client_bonus
#        $(CC) $(CFLAGS) $(SRC_S_BONUS) $(NAMELIBFT) -o server_bonus

clean:
	make -C ./libft clean

fclean: clean
	make -C ./libft fclean
	rm -rf client server
	#rm -rf client_bonus server_bonus

re: fclean all


