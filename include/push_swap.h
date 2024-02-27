/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorvath <rhorvath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:29:15 by rhorvath          #+#    #+#             */
/*   Updated: 2024/02/27 15:21:38 by rhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/* Check stuff */
int		ft_input_check(char *str);
int		ft_dup_check(char **words);
void	ft_init_check(char **words);

/* Init stuff */
char	**ft_words(char **argv);
void	ft_init_stack(char **words);
void	ft_init_nums(t_stack **stack, char **words);

/* List stuff */
t_stack	*ft_lstnew1(char *content);
int		ft_is_sorted(t_stack *stack);
t_stack	*ft_stack_max(t_stack *stack);
int		ft_stack_min(t_stack *stack);
t_stack	*ft_stack_min_2(t_stack *stack);
t_stack	*ft_find_last(t_stack *stack);
void	ft_lstadd_back1(t_stack **lst, t_stack *new);

/* Operation stuff */
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	push(t_stack **dst, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

/* Utility stuff */
int		ft_sqrt(int num);
long	ft_atol(char *str);
void	create_index(t_stack **stack);
int		ft_counter(t_stack *stack, int index);
char	*ft_strjoin1(char *s1, char const *s2);

/* Sorting stuff */
void	sorting(t_stack **stack_a, t_stack **stack_b);
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_four_v2(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	five_utils(t_stack **stack_a, t_stack **stack_b);
void	five_utils_2(t_stack **stack_a, t_stack **stack_b);
void	k_sort_1(t_stack **stack_a, t_stack **stack_b, int len);
void	k_sort_2(t_stack **stack_a, t_stack **stack_b, int len);

/* Error stuff */
void	ft_error(void);

/* Freeing stuff */
void	ft_free_stack(t_stack **stack);
void	ft_free_words(char **words);

#endif
