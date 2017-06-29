# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 22:16:11 by lmazzi            #+#    #+#              #
#    Updated: 2017/06/05 19:50:04 by lmazzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SOURCES = ft_memset.c\
		  ft_bzero.c\
		  ft_memcpy.c\
		  ft_memccpy.c\
		  ft_memmove.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_ptrlen.c\
		  ft_strlen.c\
		  ft_strdup.c\
		  ft_strcpy.c\
		  ft_strncpy.c\
		  ft_strcat.c\
		  ft_strncat.c\
		  ft_strlcat.c\
		  ft_strchr.c\
		  ft_strrchr.c\
		  ft_strstr.c\
		  ft_strnstr.c\
		  ft_strcmp.c\
		  ft_strncmp.c\
		  ft_atoi.c\
		  ft_isalpha.c\
		  ft_isdigit.c\
		  ft_isdigits.c\
		  ft_isalnum.c\
		  ft_isascii.c\
		  ft_isprint.c\
		  ft_toupper.c\
		  ft_tolower.c\
		  ft_memalloc.c\
		  ft_memdel.c\
		  ft_strnew.c\
		  ft_strdel.c\
		  ft_strclr.c\
		  ft_striter.c\
		  ft_striteri.c\
		  ft_strmap.c\
		  ft_strmapi.c\
		  ft_strequ.c\
		  ft_strnequ.c\
		  ft_strsub.c\
		  ft_strjoin.c\
		  ft_strtrim.c\
		  ft_strsplit.c\
		  ft_itoa.c\
		  ft_power.c\
		  ft_putchar.c\
		  ft_putstr.c\
		  ft_putendl.c\
		  ft_putnbr.c\
		  ft_putchar_fd.c\
		  ft_putstr_fd.c\
		  ft_putendl_fd.c\
		  ft_putnbr_fd.c\
		  ft_root.c\
		  ft_lstnew.c\
		  ft_lstdelone.c\
		  ft_lstdel.c\
		  ft_lstadd.c\
		  ft_lstiter.c\
		  ft_lstaddend.c\
		  ft_lstmap.c\
		  ft_natoi.c\
		  btree_apply_infix.c\
		  btree_apply_prefix.c\
		  btree_apply_suffix.c\
		  btree_create_node.c\
		  btree_insert_data.c\
		  get_next_line.c\
		  flag.c\
		  ft_cast_length.c\
		  ft_itoa_base_print.c\
		  ft_printf.c\
		  ft_crop_printf.c\
		  ft_width.c\
		  ft_wide.c\
		  ft_whitespaces.c\

HEADERS = libft.h

OBJECT = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SOURCES)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

clean:
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
