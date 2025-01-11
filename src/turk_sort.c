/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:38:40 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/26 14:40:10 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_three_numbers_a(t_stack *stack_a)
{
	int	max_pos;
	int	min_pos;
	int	middle_pos;

	max_pos = find_position(stack_a, stack_a->max);
	min_pos = find_position(stack_a, stack_a->min);
	middle_pos = 0;
	middle_pos = 3 - max_pos - min_pos;
	if (max_pos == 0 && middle_pos == 1 && min_pos == 2)
	{
		swap(stack_a, "sa");
		reverse_rotate(stack_a, "rra");
	}
	else if (max_pos == 0 && middle_pos == 2 && min_pos == 1)
		rotate(stack_a, "ra");
	else if (max_pos == 1 && middle_pos == 0 && min_pos == 2)
		reverse_rotate(stack_a, "rra");
	else if (max_pos == 1 && middle_pos == 2 && min_pos == 0)
	{
		reverse_rotate(stack_a, "rra");
		swap(stack_a, "sa");
	}
	else if (max_pos == 2 && middle_pos == 0 && min_pos == 1)
		swap(stack_a, "sa");
}

static void	place_min_number_on_top_a(t_push_swap *ps)
{
	int	min_pos_in_a;

	min_pos_in_a = find_position(ps->stack_a, ps->stack_a->min);
	while (ps->stack_a->top_node->value != ps->stack_a->min)
	{
		if (min_pos_in_a <= ps->stack_a->size / 2)
			rotate(ps->stack_a, "ra");
		else
			reverse_rotate(ps->stack_a, "rra");
	}
}

void	turk_sort(t_push_swap *ps, t_context *ctx)
{
	int	num_to_push;

	update_stacks(ps);
	presort(ps, ctx);
	update_stacks(ps);
	sort_three_numbers_a(ps->stack_a);
	while (ps->stack_b->size > 0)
	{
		update_stacks(ps);
		num_to_push = find_min_cost_number(ps);
		move(ps, num_to_push);
	}
	update_stacks(ps);
	place_min_number_on_top_a(ps);
}
