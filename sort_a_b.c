/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:52:26 by wzouf             #+#    #+#             */
/*   Updated: 2022/05/28 20:18:29 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	chunk_fill(t_stack *tmp)
{
	int	i;
	int	j;

	j = tmp->sorted_stack_index;
	i = -1;
	if ((ft_lstsize(tmp->b) % tmp->size) == 0 && tmp->index_t == 0)
	{
		free (tmp->chunk);
		tmp->chunk = malloc(sizeof(int) * tmp->size);
		if (!tmp->chunk)
			return (free (tmp->chunk), -1);
		while (++i < tmp->size)
		{
			tmp->chunk[i] = tmp->tab[j++];
		}
		tmp->sorted_stack_index += tmp->size;
	}
	return (0);
}

int	from_a_to_b(t_stack *tmp, t_list *node)
{
	int		i;
	int		found;

	i = -1;
	while (tmp->a)
	{
		if (chunk_fill(tmp) == -1)
			return (1);
		while (++i < tmp->size)
		{
			found = 0;
			if (node->content == tmp->chunk[i])
			{
				checker(tmp, ft_lstsize(tmp->a), 0);
				found = 1;
				node = tmp->a;
				i = tmp->size;
			}
		}
		i = -1;
		if (!found)
			node = node->next;
		tmp->index_t++;
	}
	return (0);
}

void	from_b_to_a(t_stack *tmp)
{
	int		i;
	t_list	*node;
	int		found;

	node = tmp->b;
	tmp->index_t = 0;
	i = ft_lstsize(tmp->b) - 1;
	while (tmp->b)
	{
		found = 0;
		if (node->content == tmp->tab[i])
		{
			checker(tmp, ft_lstsize(tmp->b), 1);
			found = 1;
			node = tmp->b;
			i--;
		}
		if (!found)
			node = node->next;
		tmp->index_t++;
	}
}
