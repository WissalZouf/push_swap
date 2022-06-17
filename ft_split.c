/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:36:51 by wzouf             #+#    #+#             */
/*   Updated: 2022/05/24 14:57:35 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(src);
	if (!dst || dstsize == 0)
		return (j);
	while ((src[i] != '\0') && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

void	ft_free_table(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

void	ft_gettables(char *str, char c, char **s)
{
	int	i;
	int	count;
	int	end;

	i = 0;
	count = 0;
	while (i < ft_strlen(str))
	{
		end = i;
		while (str[end] && str[end] != c)
			end++;
		if (end > i)
		{
			s[count] = malloc(sizeof(char) * (end - i + 1));
			if (!s[count])
				ft_free_table(s, count);
			ft_strlcpy(s[count], &str[i], end - i + 1);
			count++;
			i = end;
		}
		i++;
	}
	s[count] = NULL;
}

int	ft_count(char *str, char c)
{
	int	i;
	int	count;
	int	end;

	i = 0;
	count = 0;
	if (!str[0])
		return (1);
	while (i < ft_strlen(str))
	{
		end = i;
		while (str[end] && str[end] != c)
			end++;
		if (end > i)
		{
			count++;
			i = end;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**str;

	if (!s)
		return (NULL);
	count = ft_count((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	ft_gettables((char *)s, c, str);
	return (str);
}
