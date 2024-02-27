/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorvath <rhorvath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:11:59 by rhorvath          #+#    #+#             */
/*   Updated: 2024/02/27 14:03:28 by rhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	k_sort_1(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	i;
	int	range;

	i = 0;
	range = (ft_sqrt(len) - 1) * 14 / 10;
	create_index(stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_b, stack_a);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	k_sort_2(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	rbc;
	int	rrbc;

	while (len - 1 >= 0)
	{
		rbc = ft_counter(*stack_b, len - 1);
		rrbc = (len + 3) - rbc;
		if (rbc <= rrbc)
		{
			while ((*stack_b)->index != len - 1)
				rb(stack_b);
			pa(stack_a, stack_b);
			len--;
		}
		else
		{
			while ((*stack_b)->index != len - 1)
				rrb(stack_b);
			pa(stack_a, stack_b);
			len--;
		}
	}
}

int	ft_sqrt(int num)
{
	int	n;

	n = 1;
	if (num > 0)
	{
		while (n * n <= num)
		{
			if (n * n == num)
				return (n);
			else if (n >= 46341)
				return (0);
			n++;
		}
	}
	if (num % n == 0)
		return (n);
	else
		return (n - 1);
}

void	create_index(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;
	int		ind;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = *stack;
	ind = 0;
	while (ind < i)
	{
		head = ft_stack_min_2(*stack);
		head->index = ind;
		ind++;
	}
}

int	ft_counter(t_stack *stack, int index)
{
	int	i;

	i = 0;
	while (stack && stack->index != index)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
