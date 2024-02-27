/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorvath <rhorvath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:30:02 by rhorvath          #+#    #+#             */
/*   Updated: 2024/02/27 14:58:29 by rhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack		*tmp;
	t_stack		*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current->next)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(current);
	if (stack)
		free(stack);
	*stack = NULL;
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_free_words(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

int	ft_input_check(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-'
				|| str[i] == '+') || str[i] == ' ')
		{
			if (str[i] == '-' || str[i] == '+')
			{
				if (str[i + 1] != '-' && str[i + 1] != '+'
					&& (str[i + 1] < '0' || str[i + 1] > '9'))
					return (1);
			}
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (str[i + 1] == '-' || str[i + 1] == '+')
					return (1);
			}
		}
		else
			return (1);
	}
	return (0);
}

int	ft_dup_check(char **words)
{
	int		i;
	int		j;
	int		k;
	long	*tmp;

	k = 0;
	while (words[k])
		k++;
	tmp = (long *)malloc(sizeof(long) * k);
	i = -1;
	while (words[++i])
		tmp[i] = ft_atol(words[i]);
	i = -1;
	while (++i < k)
	{
		j = i + 1;
		while (j < k)
		{
			if (tmp[i] == tmp[j])
				return (free(tmp), 1);
			j++;
		}
	}
	free(tmp);
	return (0);
}
