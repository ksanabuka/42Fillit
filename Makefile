# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iiskakov <iiskakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 11:28:18 by obuksha           #+#    #+#              #
#    Updated: 2019/04/25 13:15:58 by iiskakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		$(NAME) all clean fclean re

LIBFT_PATH	=	libft/

NAME		=	fillit
FLAGS		=	-Wall -Werror -Wextra -o $(NAME) -lft -L$(LIBFT_PATH) -I$(LIBFT_PATH)
SOURCES		=	validation.c \
				try1.c \
				put_fig_on_map.c \
				make_fig_coordinates.c \
				map.c \

all:			$(NAME)

$(NAME):
				make -C $(LIBFT_PATH)
				gcc $(FLAGS) $(SOURCES)

clean:			
				make -C $(LIBFT_PATH) clean

				

fclean:			clean				
				make -C $(LIBFT_PATH) fclean
				rm -f $(NAME)

re:				fclean all