# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obuksha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 11:28:18 by obuksha           #+#    #+#              #
#    Updated: 2019/02/07 11:42:33 by obuksha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		$(NAME) all clean fclean re

LIBFT_PATH	=	libft/

NAME		=	fillit
FLAGS		=	-Wall -Werror -Wextra -o $(NAME) -lft -L$(LIBFT_PATH) -I$(LIBFT_PATH)
SOURCES		=	validation.c \
				try1.c \
				stack_status.c \
				putFigOnMap.c \
				make_fig_coordinates.c 

OBJECTS = $(SOURCES:.c=.o)


all:			$(NAME)

$(NAME):
				gcc $(FLAGS) $(SOURCES)

clean:			
				rm -rf $(OBJECTS)
				rm -rf fillit
				

fclean:			clean
				rm -f $(NAME)

re:				fclean all