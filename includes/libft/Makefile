# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 20:15:19 by skoudad           #+#    #+#              #
#    Updated: 2025/06/05 19:49:46 by skoudad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_atoi.c \
ft_itoa.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c \
ft_bzero.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c ft_calloc.c \
ft_memcmp.c ft_split.c ft_strmapi.c ft_isalnum.c ft_memcpy.c ft_strchr.c \
ft_strncmp.c ft_isalpha.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_isascii.c \
ft_memset.c ft_striteri.c ft_strrchr.c ft_isdigit.c ft_putchar_fd.c \
ft_strjoin.c ft_strtrim.c

OBJ = $(SRC:.c=.o)

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)
bonus:	$(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

re: fclean all

.PHONY: all clean fclean re bonus
