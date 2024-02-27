/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorvath <rhorvath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:28:20 by rhorvath          #+#    #+#             */
/*   Updated: 2024/02/27 15:36:46 by rhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	char	**words;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	words = ft_words(argv);
	ft_init_check(words);
	ft_init_stack(words);
	ft_free_words(words);
	return (0);
}
