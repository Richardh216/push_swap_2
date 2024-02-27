/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorvath <rhorvath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:35:44 by rhorvath          #+#    #+#             */
/*   Updated: 2024/02/27 14:16:05 by rhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*top;
	t_stack	*next_top;

	if (!*stack || !(*stack)->next)
		return ;
	top = *stack;
	next_top = (*stack)->next;
	top->next = next_top->next;
	if (next_top->next)
		next_top->next->prev = top;
	next_top->next = top;
	top->prev = next_top;
	next_top->prev = NULL;
	*stack = next_top;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
