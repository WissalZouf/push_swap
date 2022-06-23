/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:41:16 by wzouf             #+#    #+#             */
/*   Updated: 2022/06/23 02:54:39 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = b;
	i = 0;
	while (i++ < n)
		*dest++ = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}

void	ft_buff_to_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
}

void	ft_choose_action(t_stack *stack, char *cmd)
{
	if (!ft_strcmp(cmd, "sa"))
		ft_sa(stack);
	else if (!ft_strcmp(cmd, "sb"))
		ft_sb(stack);
	else if (!ft_strcmp(cmd, "ss"))
		ft_ss(stack);
	else if (!ft_strcmp(cmd, "pa"))
		ft_pa(stack);
	else if (!ft_strcmp(cmd, "pb"))
		ft_pb(stack);
	else if (!ft_strcmp(cmd, "ra"))
		ft_ra(stack);
	else if (!ft_strcmp(cmd, "rb"))
		ft_rb(stack);
	else if (!ft_strcmp(cmd, "rr"))
		ft_rr(stack);
	else if (!ft_strcmp(cmd, "rra"))
		ft_rra(stack);
	else if (!ft_strcmp(cmd, "rrb"))
		ft_rrb(stack);
	else if (!ft_strcmp(cmd, "rrr"))
		ft_rrr(stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	stack.checker = 1;
	stack.tab = NULL;
	stack.chunk = NULL;
	ft_check_args(argc, argv, stack);
	ft_free_stack(&stack);
	ft_readline(stack);
	while (1)
	{}
	// copylist(&stack);
	// if (ft_check(&stack))
	// 	write(1, "KO\n", 3);
	// else
	// 	write(1, "OK\n", 3);

}
