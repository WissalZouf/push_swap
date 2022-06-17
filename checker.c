/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:41:16 by wzouf             #+#    #+#             */
/*   Updated: 2022/06/17 21:00:21 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_bzero(void *b, size_t n)
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
		str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
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

void	ft_checkcmd(char *cmd)
{
	if (ft_strcmp(cmd, "sa") && ft_strcmp(cmd, "sb")
		&& ft_strcmp(cmd, "ss") && ft_strcmp(cmd, "pa")
		&& ft_strcmp(cmd, "pb") && ft_strcmp(cmd, "ra")
		&& ft_strcmp(cmd, "rb") && ft_strcmp(cmd, "rr")
		&& ft_strcmp(cmd, "rra") && ft_strcmp(cmd, "rrb")
		&& ft_strcmp(cmd, "rrr"))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
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

int	ft_check(t_stack *stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack->a;
	while (tmp)
	{
		if (tmp->content != stack->tab[i])
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*new;
	t_stack	stack;
	int		i;
	char	**str;
	int		j;
	char	*str1;
	char	*cmd;
	char	*tmp;

	i = 1;
	j = 0;
	new = NULL;
	stack.a = NULL;
	stack.b = NULL;
	str = NULL;

	cmd = malloc(sizeof(char) * 2);
	stack.checker = 1;
	while (argv[i] && i <= argc)
	{
		j = 0;
		str = ft_split(argv[i], ' ');
		while (str[j])
		{
			if (check_content(str[j], stack.a) && !ft_digit(str[j]))
			{
				new = ft_lstnew(ft_atoi(str[j]));
				ft_lstadd_back(new, &stack.a);
			}
			else
			{
				write(1, "ERROR", 5);
				exit(1);
			}
			j++;
		}
		i++;
	}
	copylist(&stack);
	str1 = malloc(sizeof(char));
	while (read(0, cmd, 1))
	{
		cmd[1] = '\0';
		if (cmd[0] == '\n')
		{
			ft_checkcmd(str1);
			ft_choose_action(&stack, str1);
			ft_bzero(str1, ft_strlen(str1));
		}
		else
		{
			tmp = str1;
			str1 = ft_strjoin(str1, cmd);
			free(tmp);
		}
		ft_buff_to_zero(cmd);
	}
	if (ft_check(&stack))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
