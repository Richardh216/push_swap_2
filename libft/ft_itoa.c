/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorvath <rhorvath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:22:53 by rhorvath          #+#    #+#             */
/*   Updated: 2023/04/18 14:45:00 by rhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_of_char(int n)
{
	int				i;
	unsigned int	number;

	i = 1;
	number = n;
	if (n < 0)
	{
		i = 2;
		number = -n;
	}
	while (number > 9)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	num;
	char			*str;

	str = (char *)ft_calloc(num_of_char(n) + 1, sizeof(char));
	if (!str)
		return (0);
	i = num_of_char(n);
	num = n;
	if (n < 0)
	{
		num = -n;
		*str = '-';
	}
	str[i - 1] = '0';
	while (num > 0)
	{
		i--;
		str[i] = num % 10 + 48;
		num /= 10;
	}
	return (str);
}
