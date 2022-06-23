# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 19:38:33 by wzouf             #+#    #+#              #
#    Updated: 2022/06/23 00:50:47 by wzouf            ###   ########.fr        #
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
		remove_leaks.c \
		
	
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
		checker_utils.c \
		remove_leaks.c \
		
NAME= push_swap

NAMEB = checker

CFLAGS = -Wall -Wextra -Werror
$(NAME) : $(SRCM) push_swap.h
	gcc $(CFLAGS) $(SRCM) -o ${NAME}

$(NAMEB) : $(SRCB) push_swap.h
	gcc $(CFLAGS) $(SRCB) -o $(NAMEB)


all : $(NAME)

bonus : $(NAMEB)

norm:
	norminette $(SRCM) $(SRCB) push_swap.h

clean :

fclean : clean
	rm -rf $(NAME) $(NAMEB)

re : fclean all