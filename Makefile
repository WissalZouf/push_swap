# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 19:38:33 by wzouf             #+#    #+#              #
#    Updated: 2022/06/17 21:32:42 by wzouf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCM =	utils.c  \
		linkedlist.c \
		action1.c \
		action2.c \
		action3.c \
		ft_split.c \
		pushswap.c \
		push_a.c \
		push_b.c \
		sort_a_b.c \
		free_data.c \
		create_list.c \
		small_stack.c \
		
	
SRCB =  checker.c \
		utils.c  \
		linkedlist.c \
		action1.c \
		action2.c \
		action3.c \
		ft_split.c \
		push_a.c \
		push_b.c \
		sort_a_b.c \
		free_data.c \
		create_list.c \
		small_stack.c \
		ft_checkerutils.c \
		
NAME= push_swap

NAMEB = checker

CFLAGS = -Wall -Wextra -Werror
$(NAME) : $(SRCM) push_swap.h
	gcc $(CFLAGS) $(SRCM) -o ${NAME}

$(NAMEB) : $(SRCB) push_swap.h
	gcc $(CFLAGS) $(SRCB) -o $(NAMEB)

all : $(NAME)

bonus : $(NAMEB)

clean :

fclean : clean
	rm -rf $(NAME) $(NAMEB)

re : fclean all