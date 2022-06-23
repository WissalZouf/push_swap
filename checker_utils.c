/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:19:30 by wzouf             #+#    #+#             */
/*   Updated: 2022/06/23 02:50:25 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(void)
{
	write(1, "ERROR", 5);
	exit(1);
}

void	ft_check_args(int argc, char **argv, t_stack stack)
{
	char	**str;
	int		i;
	int		j;
	t_list	*new;

	i = 0;
	j = -1;
	new = NULL;
	while (argv[++i] && i <= argc)
	{
		j = -1;
		str = ft_split(argv[i], ' ');
		while (str[++j])
		{
			if (check_content(str[j], stack.a) && !ft_digit(str[j]))
			{
				new = ft_lstnew(ft_atoi(str[j]));
				ft_lstadd_back(new, &stack.a);
			}
			else
			{
				ft_free_stack(&stack);
				free_tab_2d(str);
				ft_print_error();
			}
		}
		free_tab_2d(str);
	}
}

void	ft_readline(t_stack stack)
{
	char	*str1;
	char	*cmd;
	char	*tmp;

	cmd = malloc(sizeof(char) * 2);
	str1 = malloc(sizeof(char));
	tmp = NULL;
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
			printf("joined str1 : %s\n", str1);
			free(tmp);
		}
		ft_buff_to_zero(cmd);
	}
	free(cmd);
	free(str1);
	
	// return (free(cmd), free(str1));
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
