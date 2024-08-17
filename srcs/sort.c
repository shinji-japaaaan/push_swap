/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:09:19 by sishizaw          #+#    #+#             */
/*   Updated: 2024/08/11 11:09:22 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack_three(t_stack **stack_a)
{
	if (find_min(*stack_a) == (*stack_a)->nbr)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (find_max(*stack_a) == (*stack_a)->nbr)
	{
		ra(stack_a);
		if (!check_sorted(*stack_a))
			sa(stack_a);
	}
	else
	{
		if (find_index(*stack_a, find_max(*stack_a)) == 1)
			rra(stack_a);
		else
			sa(stack_a);
	}
}

void	sort_till_3(t_stack **stack_a, t_stack **stack_b)
{
	t_cost_info cost_info;

    while (ft_lstsize(*stack_a) > 3 && !check_sorted(*stack_a))
    {
        cost_info = get_costinfo_ab(*stack_a, *stack_b); 

        if (cost_info.operation == 0)
            apply_rarb(stack_a, stack_b, cost_info.nbr, 'a');
        else if (cost_info.operation == 1)
            apply_rrarrb(stack_a, stack_b, cost_info.nbr, 'a');
        else if (cost_info.operation == 2)
            apply_rarrb(stack_a, stack_b, cost_info.nbr, 'a');
        else if (cost_info.operation == 3)
            apply_rrarb(stack_a, stack_b, cost_info.nbr, 'a');
    }
}

t_stack	*sort_stack_ab(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !check_sorted(*stack_a))
		pb(stack_a, &stack_b);
	if (ft_lstsize(*stack_a) > 3 && !check_sorted(*stack_a))
		pb(stack_a, &stack_b);
	if (ft_lstsize(*stack_a) > 3 && !check_sorted(*stack_a))
		sort_till_3(stack_a, &stack_b);
	if (!check_sorted(*stack_a))
		sort_stack_three(stack_a);
	return (stack_b);
}

t_stack **sort_stack_ba(t_stack **stack_a, t_stack **stack_b)
{
    t_cost_info cost_info;

    while (*stack_b)
    {
        cost_info = get_costinfo_ba(*stack_a, *stack_b);

        if (cost_info.operation == 0)
            apply_rarb(stack_a, stack_b, cost_info.nbr, 'b');
        else if (cost_info.operation == 1)
            apply_rrarrb(stack_a, stack_b, cost_info.nbr, 'b');
        else if (cost_info.operation == 2)
            apply_rarrb(stack_a, stack_b, cost_info.nbr, 'b');
        else if (cost_info.operation == 3)
            apply_rrarb(stack_a, stack_b, cost_info.nbr, 'b');
    }
    return (stack_a);
}

void	sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else
	{
		stack_b = sort_stack_ab(stack_a);
		stack_a = sort_stack_ba(stack_a, &stack_b);
		i = find_index(*stack_a, find_min(*stack_a));
		if (i < ft_lstsize(*stack_a) / 2)
		{
			while ((*stack_a)->nbr != find_min(*stack_a))
				ra(stack_a);
		}
		else
		{
			while ((*stack_a)->nbr != find_min(*stack_a))
				rra(stack_a);
		}		
	}	
}
