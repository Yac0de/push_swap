/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:14:15 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/21 15:59:50 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	handle_rotate_both(t_push_swap *ps, t_rotation_info *rotate_info)
{
	while (rotate_info->count_rotate_a > 0 && rotate_info->count_rotate_b > 0)
	{
		rotate_both(ps->stack_a, ps->stack_b);
		rotate_info->count_rotate_a--;
		rotate_info->count_rotate_b--;
	}
	while (rotate_info->count_reverse_rotate_a > 0
		&& rotate_info->count_reverse_rotate_b > 0)
	{
		reverse_rotate_both(ps->stack_a, ps->stack_b);
		rotate_info->count_reverse_rotate_a--;
		rotate_info->count_reverse_rotate_b--;
	}
}

static void	handle_individual_rotates(t_push_swap *ps,
		t_rotation_info *rotate_info)
{
	while (rotate_info->count_rotate_a > 0)
	{
		rotate(ps->stack_a, "ra");
		rotate_info->count_rotate_a--;
	}
	while (rotate_info->count_rotate_b > 0)
	{
		rotate(ps->stack_b, "rb");
		rotate_info->count_rotate_b--;
	}
	while (rotate_info->count_reverse_rotate_a > 0)
	{
		reverse_rotate(ps->stack_a, "rra");
		rotate_info->count_reverse_rotate_a--;
	}
	while (rotate_info->count_reverse_rotate_b > 0)
	{
		reverse_rotate(ps->stack_b, "rrb");
		rotate_info->count_reverse_rotate_b--;
	}
}

void	move(t_push_swap *ps, int num_to_push)
{
	t_rotation_info	rotate_info;

	rotate_info.count_rotate_a = 0;
	rotate_info.count_rotate_b = 0;
	rotate_info.count_reverse_rotate_a = 0;
	rotate_info.count_reverse_rotate_b = 0;
	count_rotate_top_b(ps->stack_b, num_to_push, &rotate_info);
	count_rotate_correct_top_b(ps, num_to_push, &rotate_info);
	handle_rotate_both(ps, &rotate_info);
	handle_individual_rotates(ps, &rotate_info);
	push(ps->stack_b, ps->stack_a, "pa");
}
