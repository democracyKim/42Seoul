# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 13:19:43 by minkim3           #+#    #+#              #
#    Updated: 2023/02/28 14:32:34 by minkim3          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD
NAME		= push_swap
AR			= ar -rcs
RM			= rm -f
HEADER		= push_swap.h
LIBFT		= libft/libft.a
SOURCES		= ./operations/doubly_linked_stack.c \
			  ./operations/push.c \
			  ./operations/reverse.c \
			  ./operations/rotate.c \
			  ./operations/swap.c \
			  exit.c \
			  fill_stack.c \
			  print_stack.c

B_SOURCES	=

OBJECT		= $(SOURCES:.c=.o)
B_OBJECT	= $(B_SOURCES:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJECT) $(B_OBJECT)
else
	OBJECTS = $(OBJECT)
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft
	cp $(LIBFT) ./$(NAME)
	ar rcs $@ $^

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
bonus:
	make WITH_BONUS=1 all

clean:
	$(RM) $(OBJECTS) $(OBJECTS:.o=.d)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re:
	make fclean
	make all

.PHONY: all clean fclean re

-include $(OBJECTS:.o=.d)