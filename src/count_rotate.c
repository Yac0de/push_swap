/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:19:58 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/21 15:35:34 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	count_rotate_top_b(t_stack *stack_b, int num_to_push,
		t_rotation_info *rotate_info)
{
	int	num_pos_in_b;

	num_pos_in_b = find_position(stack_b, num_to_push);
	if (num_pos_in_b == 0)
		return ;
	else if (num_pos_in_b <= stack_b->size / 2)
		rotate_info->count_rotate_b = num_pos_in_b;
	else
		rotate_info->count_reverse_rotate_b = stack_b->size - num_pos_in_b;
}

void	count_rotate_correct_top_b(t_push_swap *ps, int num_to_push,
		t_rotation_info *rotate_info)
{
	int	min_pos_in_a;
	int	next_higher_num;
	int	next_higher_num_pos;

	min_pos_in_a = find_position(ps->stack_a, ps->stack_a->min);
	if (num_to_push > ps->stack_a->max)
	{
		if (min_pos_in_a > ps->stack_a->size / 2)
			rotate_info->count_reverse_rotate_a = ps->stack_a->size
				- min_pos_in_a;
		else
			rotate_info->count_rotate_a = min_pos_in_a;
	}
	else
	{
		next_higher_num = ft_next_higher_num(ps->stack_a, num_to_push);
		next_higher_num_pos = find_position(ps->stack_a, next_higher_num);
		if (next_higher_num_pos > ps->stack_a->size / 2)
			rotate_info->count_reverse_rotate_a = ps->stack_a->size
				- next_higher_num_pos;
		else
			rotate_info->count_rotate_a = next_higher_num_pos;
	}
}
