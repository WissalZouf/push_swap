/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:22:29 by wzouf             #+#    #+#             */
/*   Updated: 2022/06/17 21:18:28 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *tmp)
{
	t_list	*node_tmp;
	t_list	*head;

	if (!tmp->a || !tmp->a->next)
		return ;
	head = tmp->a->next;
	node_tmp = tmp->a;
	while (tmp->a->next != NULL)
		tmp->a = tmp->a->next;
	tmp->a->next = node_tmp;
	node_tmp->next = NULL;
	tmp->a = head;
	if (tmp->msg_status == 0 && !tmp->checker)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack *tmp)
{
	t_list	*node_tmp;
	t_list	*head;

	if (!tmp->b || !tmp->b->next)
		return ;
	head = tmp->b->next;
	node_tmp = tmp->b;
	while (tmp->b->next != NULL)
		tmp->b = tmp->b->next;
	tmp->b->next = node_tmp;
	node_tmp->next = NULL;
	tmp->b = head;
	if (tmp->msg_status == 0 && !tmp->checker)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack *tmp)
{
	tmp->msg_status = 1;
	write(1, "rr\n", 3);
	ft_ra(tmp);
	ft_rb(tmp);
	tmp->msg_status = 0;
}

void	ft_rrb(t_stack *tmp)
{
	t_list	*node_tmp;
	t_list	*head;

	if (!tmp->b || !tmp->b->next)
		return ;
	head = tmp->b;
	while (tmp->b->next != NULL)
	{
	node_tmp = tmp->b;
	tmp->b = tmp->b->next;
	}
	tmp->b->next = head;
	node_tmp->next = NULL;
	if (tmp->msg_status == 0 && !tmp->checker)
		write(1, "rrb\n", 4);
}

void	ft_rra(t_stack *tmp)
{
	t_list	*node_tmp;
	t_list	*head;

	if (!tmp->a || !tmp->a->next)
		return ;
	head = tmp->a;
	while (tmp->a->next != NULL)
	{
		node_tmp = tmp->a;
		tmp->a = tmp->a->next;
	}
	tmp->a->next = head;
	node_tmp->next = NULL;
	if (tmp->msg_status == 0 && !tmp->checker)
		write(1, "rra\n", 4);
}
