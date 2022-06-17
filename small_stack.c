/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:59:10 by wzouf             #+#    #+#             */
/*   Updated: 2022/05/24 15:42:55 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_norm(t_stack *stack)
{
	if (stack->a->content < stack->a->next->content \
	&& stack->a->next->next->content > stack->a->content \
	&& stack->a->next->content > stack->a->next->next->content)
	{
		stack->msg_status = 0;
		ft_sa(stack);
		ft_ra(stack);
	}
	if (stack->a->content < stack->a->next->content \
	&& stack->a->next->content > stack->a->next->next->content)
	{
		stack->msg_status = 0;
		ft_rra (stack);
	}
}

void	ft_small_stack(t_stack *stack)
{
	if (stack->a->content > stack->a->next->content \
	&& stack->a->next->content > stack->a->next->next->content)
	{
		stack->msg_status = 0;
		ft_sa(stack);
		ft_rra(stack);
	}
	if (stack->a->content > stack->a->next->content \
	&& stack->a->next->content < stack->a->next->next->content \
	&& stack->a->content > stack->a->next->next->content)
	{
		stack->msg_status = 0;
		ft_ra(stack);
	}
	if (stack->a->content > stack->a->next->content \
	&& stack->a->next->content < stack->a->next->next->content)
	{
		stack->msg_status = 0;
		ft_sa(stack);
	}
	ft_norm(stack);
}
