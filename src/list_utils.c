/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorvath <rhorvath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:56:08 by rhorvath          #+#    #+#             */
/*   Updated: 2024/02/27 18:28:44 by rhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	if (!stack)
		return (-1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*ft_stack_max(t_stack *stack)
{
	int		max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->num > max)
		{
			max = stack->num;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

int	ft_stack_min(t_stack *stack)
{
	long	min;
	int		i;
	int		res;

	res = 0;
	i = 0;
	if (!stack)
		return (-1);
	min = stack->num;
	while (stack)
	{
		if (stack->num < min)
		{
			min = stack->num;
			res = i;
		}
		i++;
		stack = stack->next;
	}
	return (res);
}

t_stack	*ft_stack_min_2(t_stack *stack)
{
	t_stack	*min_node;
	t_stack	*tmp;
	long	min;
	int		i;

	i = 0;
	if (!stack)
		return (NULL);
	min_node = stack;
	tmp = stack;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->num < min && tmp->index == -1)
		{
			min = tmp->num;
			min_node = tmp;
		}
		i++;
		tmp = tmp->next;
	}
	return (min_node);
}
