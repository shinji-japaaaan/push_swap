/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:09:59 by sishizaw          #+#    #+#             */
/*   Updated: 2024/08/11 11:10:01 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_stack *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr < i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

int	find_max(t_stack *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr > i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

int	find_index(t_stack *a, int c)
{
	int		i;

	i = 0;
	while (a->nbr != c)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

int	find_place_b(t_stack *stack_b, int c)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (c > stack_b->nbr && c < ft_lstlast(stack_b)->nbr)
		i = 0;
	else if (c > find_max(stack_b) || c < find_min(stack_b))
		i = find_index(stack_b, find_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->nbr < c || tmp->nbr > c)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	find_place_a(t_stack *stack_a, int c)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (c < stack_a->nbr && c > ft_lstlast(stack_a)->nbr)
		i = 0;
	else if (c > find_max(stack_a) || c < find_min(stack_a))
		i = find_index(stack_a, find_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (!(stack_a->nbr < c && c < tmp->nbr))
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
