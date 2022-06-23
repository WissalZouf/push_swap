/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_leaks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:48:25 by wzouf             #+#    #+#             */
/*   Updated: 2022/06/23 01:41:05 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_tab_2d(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_free_list(t_list *a)
{
	t_list *tmp;

	if (a)
	{
		while (a->next)
		{
			tmp = a;
			a = a->next;
			free(tmp);
		}
	}
}

void	ft_free_stack(t_stack *stack)
{
	if (stack->tab)
		free(stack->tab);
	if (stack->chunk)
		free(stack->chunk);
	ft_free_list(stack->a);
	ft_free_list(stack->b);
}