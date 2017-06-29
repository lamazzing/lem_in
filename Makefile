# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 01:01:07 by lmazzi            #+#    #+#              #
#    Updated: 2017/06/06 05:06:04 by lmazzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lem-in

FILE_LIST	=   lem_in.c\
				ft_rooms.c\
				ft_algo.c\
				ft_pathfinder.c\
				ft_bestpath.c\
				ft_antgen.c\
				ft_firestarter.c\
				ft_printants.c\
				ft_apply_ants.c\
				ft_create_path_tab.c\

OBJ_FILES	=	$(FILE_LIST:.c=.o)

LIB_FT		=	./libft
LIB_FT_INC	=	-I $(LIB_FT)

LIB_FT_LINK	=	$(LIB_FT)/libft.a

INCLUDES	=	$(LIB_FT_INC)
LINK		=	$(LIB_FT_LINK)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

libs:
	@make -C $(LIB_FT)

$(NAME): libs $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LINK) $(OBJ_FILES) -o $(NAME)

$(OBJ_FILES):
	$(CC) $(CFLAGS) $(INCLUDES) -c $(FILE_LIST)

clean:
	@make -C $(LIB_FT) clean
	rm -f $(OBJ_FILES)

fclean: clean 
	@make -C $(LIB_FT) fclean
	rm -f $(NAME)

relibs:
	@make -C $(LIB_FT) re
	@make re --no-print-directory

re: fclean all

.PHONY: all clean fclean re
