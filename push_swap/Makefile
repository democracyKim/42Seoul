# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 13:19:43 by minkim3           #+#    #+#              #
#    Updated: 2023/03/11 21:26:06 by hyojocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD
NAME		= push_swap.a
AR			= ar -rcs
RM			= rm -f
HEADER		= push_swap.h
LIBFT		= libft/libft.a
SOURCES		= ./operations/push.c\
			  ./operations/reverse.c\
			  ./operations/rotate.c\
			  ./operations/swap.c\
			  ./utils/stack_utils.c\
			  ./utils/stack_utils2.c\
			  ./utils/get_pivot.c\
			  ./utils/exit.c\
			  ./utils/doubly_linked_stack.c\
			  utils.c\
			  push_swap.c\
			  fill_stack.c\
			  sort_numbers_a.c\
			  sort_numbers_b.c\
			  main.c\
			  greedy.c\
			  cost_calculation.c\

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
	cc $(CFLAGS) $(NAME) -o push_swap

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
	rm push_swap

re:
	make fclean
	make all

.PHONY: all clean fclean re

-include $(OBJECTS:.o=.d)
