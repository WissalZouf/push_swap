/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:23:19 by wzouf             #+#    #+#             */
/*   Updated: 2022/05/28 19:02:44 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_norm3(long total)
{
	if (total > 2147483647)
	{
		write(1, "error!\n", 6);
		exit(0);
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	long	total;

	i = 0;
	j = 1;
	total = 0;
	while (str[i] && (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' \
	|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v'))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i] - 48);
		ft_norm3(total);
		i++;
	}
	return (total * j);
}

int	ft_digit(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
			return (1);
		if (str[i] == '-' && i != 0)
			return (1);
		if (i == 0 && str[i] == '-' && !str[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	checkmax(long n)
{
	if (n > 2147483647)
	{
		write(1, "error\n", 6);
		exit(0);
	}
}

int	check_content(char *str, t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->content == ft_atoi(str))
			return (0);
		list = list->next;
	}
	return (1);
}
