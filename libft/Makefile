# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 21:16:37 by fbeatris          #+#    #+#              #
#    Updated: 2022/02/05 21:55:24 by fbeatris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strtrim.c \
ft_substr.c ft_tolower.c ft_toupper.c ft_atoi16.c \
ft_strcmp.c ft_atof.c get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

%.o:%.c
		gcc ${FLAGS} -o $@ -c $<

$(NAME): ${OBJ} ${HEADER}
		ar r ${NAME} ${OBJ}

all: $(NAME)

clean:
		rm -rf $(OBJ)

fclean:	clean
		rm -rf ${NAME}

re: fclean all

.PHONY: clean fclean re