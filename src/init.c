/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorvath <rhorvath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:53:15 by rhorvath          #+#    #+#             */
/*   Updated: 2024/02/27 18:24:20 by rhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**ft_words(char **argv)
{
	int		i;
	char	**words;
	char	*tmp;
	char	*str;

	i = 1;
	tmp = ft_strdup(argv[1]);
	str = ft_strdup(" ");
	while (argv[++i])
	{
		tmp = ft_strjoin1(tmp, str);
		tmp = ft_strjoin1(tmp, argv[i]);
	}
	free(str);
	words = ft_split(tmp, ' ');
	free(tmp);
	return (words);
}

void	ft_init_check(char **words)
{
	int		i;
	long	n;

	n = 0;
	i = -1;
	while (words[++i])
	{
		if (ft_input_check(words[i]))
			ft_error();
		n = ft_atol(words[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_error();
	}
	if (ft_dup_check(words))
		ft_error();
}

void	ft_init_stack(char **words)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	if (stack_a == NULL)
		return ;
	ft_init_nums(stack_a, words);
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	*stack_b = NULL;
	if (stack_b == NULL)
		return ;
	sorting(stack_a, stack_b);
	ft_free_stack(stack_a);
	free(stack_b);
}

void	ft_init_nums(t_stack **stack, char **words)
{
	int		i;
	int		j;
	t_stack	*new;
	t_stack	*tmp;

	i = 0;
	j = 1;
	while (words[i])
		i++;
	*stack = ft_lstnew1(words[0]);
	tmp = *stack;
	tmp->index = -1;
	while (j < i)
	{
		new = ft_lstnew1(words[j]);
		ft_lstadd_back1(stack, new);
		new->index = -1;
		new->prev = tmp;
		tmp = tmp->next;
		j++;
	}
}

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i == 2 && !ft_is_sorted(*stack_a))
		sort_two(stack_a);
	else if (i == 3 && !ft_is_sorted(*stack_a))
		sort_three(stack_a);
	else if (i == 4 && !ft_is_sorted(*stack_a))
		sort_four(stack_a, stack_b);
	else if (i == 5 && !ft_is_sorted(*stack_a))
		sort_five(stack_a, stack_b);
	else if (i > 5 && !ft_is_sorted(*stack_a))
	{
		k_sort_1(stack_a, stack_b, i);
		k_sort_2(stack_a, stack_b, i);
	}
}
