/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:22:40 by wzouf             #+#    #+#             */
/*   Updated: 2022/06/22 23:13:34 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stack *tmp)
{
	tmp->msg_status = 1;
	ft_rra(tmp);
	ft_rrb(tmp);
	if (tmp->msg_status == 1 && tmp->checker)
		write(1, "rrr\n", 4);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	c;

	c = 0;
	while (c++ < size - 1)
	{
		i = -1;
		while (++i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab [i + 1] = temp;
			}			
		}	
	}
}

void	copylist(t_stack *stack)
{
	int		*tab;
	int		i;
	t_list	*tmp;
	int		size;

	size = ft_lstsize(stack->a);
	stack->size = size;
	tab = malloc(sizeof(int) * size);
	i = 0;
	tmp = stack->a;
	while (tmp)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	ft_sort_int_tab(tab, size);
	stack->index = (ft_lstsize(stack->a) / 2) - 1;
	stack->mid = tab[stack->index];
	stack->tab = tab;
}
