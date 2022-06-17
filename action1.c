/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:21:49 by wzouf             #+#    #+#             */
/*   Updated: 2022/06/17 21:20:09 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *tmp)
{
	int	tmp_content;

	if (!tmp->a || tmp->a->next == NULL)
		return ;
	tmp_content = tmp->a->content;
	tmp->a->content = tmp->a->next->content;
	tmp->a->next->content = tmp_content;
	if (tmp->msg_status == 0 && !tmp->checker)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *tmp)
{
	int	tmp_content;

	if (tmp->b && tmp->b->next != NULL)
	{
		tmp_content = tmp->b->content;
		tmp->b->content = tmp->b->next->content;
		tmp->b->next->content = tmp_content;
		if (tmp->msg_status == 0 && !tmp->checker)
			write(1, "sb\n", 3);
	}
	return ;
}

void	ft_ss(t_stack *tmp)
{
	tmp->msg_status = 1;
	ft_sa(tmp);
	ft_sb(tmp);
	if (tmp->msg_status == 1 && !tmp->checker)
		write(1, "ss\n", 3);
	// tmp->msg_status = 0;
}

void	ft_pa(t_stack *tmp)
{
	t_list	*node_tmp1;
	t_list	*node_tmp2;

	if (!tmp->b)
		return ;
	node_tmp1 = tmp->a;
	node_tmp2 = tmp->b->next;
	tmp->a = tmp->b;
	tmp->b = node_tmp2;
	tmp->a->next = node_tmp1;
	if (tmp->msg_status == 0 && !tmp->checker)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stack *tmp)
{
	t_list	*node_tmp1;
	t_list	*node_tmp2;

	if (!tmp->a)
		return ;
	if (tmp->msg_status == 0 && !tmp->checker)
		write(1, "pb\n", 3);
	if (tmp->b)
	{
		node_tmp1 = tmp->a->next;
		node_tmp2 = tmp->b;
		tmp->b = tmp->a;
		tmp->a = node_tmp1;
		tmp->b->next = node_tmp2;
		return ;
	}
	node_tmp1 = tmp->a->next;
	tmp->b = tmp->a;
	tmp->a = node_tmp1;
	tmp->b->next = NULL;
}
