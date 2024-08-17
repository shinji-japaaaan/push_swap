/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:10:42 by sishizaw          #+#    #+#             */
/*   Updated: 2024/08/11 11:10:43 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_print_stack(t_stack *stack, const char *stack_name)
{
    t_stack *current = stack;
    
    printf("%s:\n", stack_name);
    while (current)
    {
        printf("%ld ", current->nbr);
        current = current->next;
    }
    printf("\n");
}

void display_error(void) {
    write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = tmp;
	}
}