/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:03:39 by wzouf             #+#    #+#             */
/*   Updated: 2022/06/23 00:46:17 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_test(t_stack *stack, char *str)
{
	t_list	*new;

	new = NULL;
	if (!ft_digit(str) && check_content(str, stack->a))
	{
		new = ft_lstnew(ft_atoi(str));
		ft_lstadd_back(new, &stack->a);
	}
	else
	{
		ft_free_stack(stack);
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	create_list(t_stack *stack, char **argv)
{
	int		i;
	char	**str;
	int		j;

	i = 1;
	j = -1;
	stack->a = NULL;
	str = NULL;
	while (argv[i])
	{
		j = -1;
		str = ft_split(argv[i], ' ');
		while (str[++j])
			ft_test(stack, str[j]);
		free_tab_2d(str);
		i++;
	}
}
