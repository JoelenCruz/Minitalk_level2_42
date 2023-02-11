# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 11:04:16 by jcruz-da          #+#    #+#              #
#    Updated: 2023/02/11 13:58:32 by jcruz-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_itoa.c \
	ft_split.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_striteri.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strtrim.c \
	ft_strjoin.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_substr.c \
	get_next_line.c \
	ft_strjoin_gnl.c \
	ft_string.c \
	ft_putcharacter_length.c \
	ft_number.c \
	ft_hexadecimal.c \
	ft_unsigned_int.c \
	ft_pointer.c \
	ft_printf.c \
	ft_strjoin_gnl.c \
	get_next_line.c \
	ft_strchr_gnl.c \
	ft_strdup_gnl.c \
	ft_substr_gnl.c 

OBJS  = $(SRCS:.c=.o)

CC  = cc

CFLAGC = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -crs $@ $^
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled Libft.\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiling $<\033[0m"

clean: 
	rm -rf $(OBJS)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean: clean
	rm -rf $(NAME)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Libft.a deleted.\033[\0m"

re: fclean all

.PHONY: all clean fclean re
