/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:23:02 by wzouf             #+#    #+#             */
/*   Updated: 2022/06/17 21:21:38 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	big_stack(t_stack *tmp)
{
	t_list	*node;

	node = tmp->a;
	if (from_a_to_b(tmp, node))
		return (1);
	from_b_to_a(tmp);
	return (0);
}

void	ft_norm1(t_stack *stack)
{
	if (ft_lstsize(stack->a) == 2)
	{
		if (stack->a->content > stack->a->next->content)
			ft_sa(stack);
	}
	else if (ft_lstsize(stack->a) <= 20)
	{
		stack->size = ft_lstsize(stack->a) / 5;
		big_stack(stack);
	}
	else if (ft_lstsize(stack->a) <= 100)
	{
		stack->size = ft_lstsize(stack->a) / 6;
		big_stack(stack);
	}
	else if (ft_lstsize(stack->a) <= 500)
	{
		stack->size = ft_lstsize(stack->a) / 12;
		big_stack(stack);
	}
}

void	ft_fix(t_stack *stack)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		value;
	int		index;

	tmp = stack->a;
	value = tmp->content;
	tmp1 = tmp;
	index = 0;
	stack->index_t = 0;
	while (tmp)
	{
		if (tmp->content < value)
		{
			tmp1 = tmp;
			index = stack->index_t;
			value = tmp->content;
		}
		stack->index_t++;
		tmp = tmp->next;
	}
	stack->index_t = index;
	pushing_b(stack, ft_lstsize(stack->a));
}

void	ft_check_size(t_stack *stack)
{
	copylist(stack);
	if (ft_lstsize(stack->a) == 3)
		ft_small_stack(stack);
	else if (ft_lstsize(stack->a) == 4)
	{
		ft_fix(stack);
		ft_small_stack(stack);
		ft_pa(stack);
	}
	else if (ft_lstsize(stack->a) == 5)
	{
		ft_fix(stack);
		ft_fix(stack);
		ft_small_stack(stack);
		ft_pa(stack);
		ft_pa(stack);
	}
	else
		ft_norm1(stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.checker = 0;
	if (argc < 2)
		return (0);
	create_list(&stack, argv);
	if (ft_lstsize(stack.a) < 2)
		return (0);
	stack.index_t = 0;
	stack.chunk = NULL;
	stack.sorted_stack_index = 0;
	stack.b = NULL;
	ft_check_size(&stack);
}
