/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:08:16 by sishizaw          #+#    #+#             */
/*   Updated: 2024/08/17 08:46:12 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = input(argc, argv);
	ft_print_stack(a, "a");
	if (!a || !checkup(a))
	{
		ft_free(&a);
		display_error();
	}
	if (!check_sorted(a))
		sort_stack(&a);
	ft_print_stack(a, "a");
	ft_free(&a);
	return (0);
}
