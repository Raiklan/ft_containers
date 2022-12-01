# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saich <saich@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 17:25:33 by saich             #+#    #+#              #
#    Updated: 2022/12/01 18:46:32 by saich            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_containers
NAME1	=	std_containers

CC		=	c++
RM		=	rm -rf
SRCS	=	main.cpp
OBJS	=	main.o
OBJS1	=	std_main.o
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
INCL	=	.

all:	$(NAME) $(NAME1)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@ -I$(INCL)

$(NAME1):	$(OBJS1)
			$(CC) $(CFLAGS) $(OBJS1) -o $@ -I$(INCL)

main.o:	main.cpp
			$(CC) $(CFLAGS) -c main.cpp -o main.o -D NAMESPACE=ft -I$(INCL)

std_main.o:	main.cpp
				$(CC) $(CFLAGS) -c main.cpp -o std_main.o -D NAMESPACE=std -I$(INCL)

clean:
			$(RM) $(OBJS) $(OBJS1)

fclean:		clean
			$(RM) $(NAME) $(NAME1)

re:			fclean all

.PHONY:		re, all, clean, fclean
