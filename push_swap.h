/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:07:53 by sishizaw          #+#    #+#             */
/*   Updated: 2024/08/11 11:07:56 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_cost_info {
    int cost;
    int nbr;
    int operation;
} t_cost_info;

void ft_print_stack(t_stack *stack, const char *stack_name);

void		ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack		*ft_stack_new(int content);
int			checkup(t_stack *a);
void 		display_error(void);
void		ft_free(t_stack **lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		sa(t_stack **a);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **a);
void		ss(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rrr_sub(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
t_stack		*ft_lstlast(t_stack *lst);
int			ft_lstsize(t_stack *lst);
int			find_min(t_stack *a);
int			find_max(t_stack *a);
int			find_index(t_stack *a, int c);
int			find_place_b(t_stack *stack_b, int nbr_push);
int			find_place_a(t_stack *a, int nbr);
void		sort_stack(t_stack **stack_a);
int			check_sorted(t_stack *stack_a);
void		sort_stack_abig(t_stack **stack_a);
void		sort_stack_three(t_stack **stack_a);
int			case_rarb_ba(t_stack *a, t_stack *b, int c);
int			case_rrarrb_ba(t_stack *a, t_stack *b, int c);
int			case_rarrb_ba(t_stack *a, t_stack *b, int c);
int			case_rrarb_ba(t_stack *a, t_stack *b, int c);
int			case_rarb(t_stack *a, t_stack *b, int c);
int			case_rrarrb(t_stack *a, t_stack *b, int c);
int			case_rrarb(t_stack *a, t_stack *b, int c);
int			case_rarrb(t_stack *a, t_stack *b, int c);
t_cost_info get_costinfo_ab(t_stack *a, t_stack *b);
t_cost_info get_costinfo_ba(t_stack *a, t_stack *b);
int			apply_rarb(t_stack **a, t_stack **b, int c, char s);
int			apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int			apply_rarrb(t_stack **a, t_stack **b, int c, char s);
void		rrb(t_stack **b);
t_stack		*input(int argc, char **argv);
void		sort_till_3(t_stack **stack_a, t_stack **stack_b);
int	ft_atoi2(const char *str);

#endif