/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:57:18 by wzouf             #+#    #+#             */
/*   Updated: 2022/05/20 16:28:53 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b_top(int index, t_stack *tmp)
{
	int	i;

	i = 0;
	tmp->msg_status = 0;
	while (i < index)
	{
		ft_ra(tmp);
		i++;
	}
	ft_pb(tmp);
}

void	push_to_b_bottom(int index, t_stack *tmp)
{
	int	i;

	i = ft_lstsize(tmp->a);
	tmp->msg_status = 0;
	while (i > index)
	{
		ft_rra(tmp);
		i--;
	}
	ft_pb(tmp);
}
