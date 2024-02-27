/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorvath <rhorvath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:33:41 by rhorvath          #+#    #+#             */
/*   Updated: 2024/02/27 14:47:01 by rhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_four_v2(t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_is_sorted(*stack_a))
	{
		pb(stack_b, stack_a);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
}

void	five_utils(t_stack **stack_a, t_stack **stack_b)
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
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (i == 4)
		rra(stack_a);
	pb(stack_b, stack_a);
	five_utils_2(stack_a, stack_b);
}

void	five_utils_2(t_stack **stack_a, t_stack **stack_b)
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
	pb(stack_b, stack_a);
}
