/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:22:52 by wzouf             #+#    #+#             */
/*   Updated: 2022/06/14 21:07:21 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int		*tab;
	int		sorted_stack_index;
	int		size;
	int		*chunk;
	int		index_t;
	int		msg_status;
	int		checker;
	int		index;
	t_list	*a;
	t_list	*b;
	int		mid;

}	t_stack;

t_list	*ft_lstnew(int content);
int		from_a_to_b(t_stack *tmp, t_list *node);
void	from_b_to_a(t_stack *tmp);
int		chunk_fill(t_stack *tmp);
void	pushing_a(t_stack *tmp, int list_size);
void	pushing_b(t_stack *tmp, int list_size);
void	checker(t_stack *tmp, int list_size, int is_a);
void	push_to_b_top(int index, t_stack *tmp);
void	push_to_b_bottom(int index, t_stack *tmp);
void	push_to_a_bottom(int index, t_stack *tmp);
void	push_to_a_top(int index, t_stack *tmp);
int		check_index2(t_stack *stack);
t_list	*ft_lstlast(t_list *lst);
int		check_index(t_list *list, int num);
void	ft_lstadd_back(t_list *new, t_list **lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
int		ft_digit(char *str);
void	checkmax(long n);
int		check_content(char *str, t_list *list);
void	ft_sa(t_stack *tmp);
void	ft_sb(t_stack *mp);
void	ft_ss(t_stack *tmp);
void	ft_pb(t_stack *tmp);
void	ft_pa(t_stack *tmp);
void	ft_ra(t_stack *tmp);
void	ft_rb(t_stack *tmp);
void	ft_rr(t_stack *tmp);
void	ft_rra(t_stack *tmp);
void	ft_rrb(t_stack *tmp);
void	ft_rrr(t_stack *tmp);
void	ft_sort_int_tab(int *tab, int size);
void	copylist(t_stack *stack);
void	ft_sorting(t_stack *stack);
int		ft_search(t_stack *stack);
void	ft_small_stack(t_stack *stack);
void	ft_finalsort(t_stack *stack);
void	ft_check_size(t_stack *stack);
int		ft_strlen(char *str);
int		ft_strlcpy(char *dst, char *src, int dstsize);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
void	ft_checkcmd(char *cmd);
void	ft_buff_to_zero(char *str);
void	ft_choose_action(t_stack *stack, char *cmd);
int		ft_check(t_stack *stack);
void	free_tab_2d(char **str);
void	create_list(t_stack *stack, char **argv);
void	free_list(t_stack *stack);

#endif