/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:54:48 by wzouf             #+#    #+#             */
/*   Updated: 2022/05/24 15:23:37 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a_top(int index, t_stack *tmp)
{
	int	i;

	i = 0;
	tmp->msg_status = 0;
	if (index == 1)
	{
		ft_sb(tmp);
		i = 1;
	}
	while (i < index)
	{
		if (i + 1 == index)
			ft_sb(tmp);
		else
			ft_rb(tmp);
		i++;
	}
	ft_pa(tmp);
}

void	push_to_a_bottom(int index, t_stack *tmp)
{
	int	i;

	tmp->msg_status = 0;
	i = ft_lstsize(tmp->b);
	while (i > index)
	{
		ft_rrb(tmp);
		i--;
	}
	ft_pa(tmp);
}

void	pushing_a(t_stack *tmp, int list_size)
{
	if (tmp->index_t <= (list_size / 2))
	{
		push_to_a_top(tmp->index_t, tmp);
		tmp->index_t = -1;
	}
	else
	{
		push_to_a_bottom(tmp->index_t, tmp);
		tmp->index_t = -1;
	}
}

void	pushing_b(t_stack *tmp, int list_size)
{
	if (tmp->index_t <= (list_size / 2))
	{
		push_to_b_top(tmp->index_t, tmp);
		tmp->index_t = -1;
	}
	else
	{
		push_to_b_bottom(tmp->index_t, tmp);
		tmp->index_t = -1;
	}
}

void	checker(t_stack *tmp, int list_size, int is_a)
{
	if (is_a)
		pushing_a(tmp, list_size);
	else
		pushing_b(tmp, list_size);
}
