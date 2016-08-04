# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpepin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 05:02:39 by jpepin            #+#    #+#              #
#    Updated: 2016/05/14 08:04:56 by jpepin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./ft_itoa.c ./ft_strcat.c ./ft_strchr.c \
	  ./ft_strcpy.c ./ft_strdup.c ./ft_strjoin.c \
	  ./ft_strmap.c ./ft_strmapi.c ./ft_strncat.c \
	  ./ft_strncmp.c ./ft_strnew.c ./ft_strnstr.c \
	  ./ft_strrchr.c ./ft_strstr.c ./ft_strsub.c \
	  ./ft_strtrim.c ./ft_strncpy.c ./ft_atoi.c \
	  ./ft_atoi.c ./ft_strcmp.c ./ft_strequ.c \
	  ./ft_strncmp.c ./ft_strnequ.c ./ft_tolower.c \
	  ./ft_toupper.c ./ft_strlcat.c ./ft_strlen.c \
	  ./ft_strclr.c ./ft_strdel.c ./ft_striter.c \
	  ./ft_striteri.c ./ft_putchar.c ./ft_putchar_fd.c \
	  ./ft_putstr.c ./ft_putstr_fd.c ./ft_putnbr.c \
	  ./ft_putnbr_fd.c ./ft_putendl.c ./ft_putendl_fd.c \
	  ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c \
	  ./ft_isdigit.c ./ft_isprint.c ./ft_memcmp.c \
	  ./ft_bzero.c ./ft_memalloc.c ./ft_memccpy.c \
	  ./ft_memchr.c ./ft_memcpy.c ./ft_memdel.c \
	  ./ft_memmove.c ./ft_memset.c ./jy_signof.c \
	  ./jy_intlen.c ./ft_strsplit.c ./ft_lstadd.c \
	  ./ft_lstdel.c ./ft_lstdelone.c ./ft_lstmap.c \
	  ./ft_lstiter.c ./ft_lstnew.c ./jy_pui.c \
	  ./jy_btree_add.c ./jy_btree_check.c ./ft_putbin.c \
	  ./jy_btree_cmp.c ./jy_btree_new.c ./jy_lstncmp.c

OBJ = ./ft_itoa.o ./ft_strcat.o ./ft_strchr.o \
	  ./ft_strcpy.o ./ft_strdup.o ./ft_strjoin.o \
	  ./ft_strmap.o ./ft_strmapi.o ./ft_strncat.o \
	  ./ft_strncmp.o ./ft_strnew.o ./ft_strnstr.o \
	  ./ft_strrchr.o ./ft_strstr.o ./ft_strsub.o \
	  ./ft_strtrim.o ./ft_strncpy.o ./ft_atoi.o \
	  ./ft_atoi.o ./ft_strcmp.o ./ft_strequ.o \
	  ./ft_strncmp.o ./ft_strnequ.o ./ft_tolower.o \
	  ./ft_toupper.o ./ft_strlcat.o ./ft_strlen.o \
	  ./ft_strclr.o ./ft_strdel.o ./ft_striter.o \
	  ./ft_striteri.o ./ft_putchar.o ./ft_putchar_fd.o \
	  ./ft_putstr.o ./ft_putstr_fd.o ./ft_putnbr.o \
	  ./ft_putnbr_fd.o ./ft_putendl.o ./ft_putendl_fd.o \
	  ./ft_isalnum.o ./ft_isalpha.o ./ft_isascii.o \
	  ./ft_isdigit.o ./ft_isprint.o ./ft_memcmp.o \
	  ./ft_bzero.o ./ft_memalloc.o ./ft_memccpy.o \
	  ./ft_memchr.o ./ft_memcpy.o ./ft_memdel.o \
	  ./ft_memmove.o ./ft_memset.o ./jy_signof.o \
	  ./jy_intlen.o ./ft_strsplit.o ./ft_lstadd.o \
	  ./ft_lstdel.o ./ft_lstdelone.o ./ft_lstmap.o \
	  ./ft_lstiter.o ./ft_lstnew.o ./jy_pui.o \
	  ./jy_btree_add.o ./jy_btree_check.o ./ft_putbin.o\
	  ./jy_btree_cmp.o ./jy_btree_new.o ./jy_lstncmp.o


all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -I./ -c $(SRC)
	@ar rc libft.a $(OBJ)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
