/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorvath <rhorvath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:16:49 by rhorvath          #+#    #+#             */
/*   Updated: 2024/02/27 13:37:30 by rhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
}

void	sort_three(t_stack **stack)
{
	t_stack	*max_node;

	max_node = ft_stack_max(*stack);
	if (max_node == *stack)
		ra(stack);
	else if ((*stack)->next == max_node)
		rra(stack);
	sort_two(stack);
	if ((*stack)->next->num > (*stack)->next->next->num)
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = ft_stack_min(*stack_a);
	if (i == 1)
		sa(stack_a);
	else if (i == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (i == 3)
		rra(stack_a);
	sort_four_v2(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	five_utils(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
