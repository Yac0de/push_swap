/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_cost_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:58:20 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/26 13:36:26 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	count_min_rotate_to_top(t_stack *stack, int number)
{
	int	min_rotate;
	int	number_pos;
	int	stack_size;

	min_rotate = 0;
	number_pos = find_position(stack, number);
	stack_size = stack->size;
	if (number_pos == 0)
		return (0);
	else if (number_pos <= stack_size / 2)
		min_rotate = number_pos;
	else
		min_rotate = stack_size - number_pos;
	return (min_rotate);
}

static void	calculate_cost_a(t_push_swap *ps, int num_to_push, int *cost)
{
	int	min_a_pos;
	int	num_just_higher;
	int	num_just_higher_pos;

	if (num_to_push > ps->stack_a->max)
	{
		min_a_pos = find_position(ps->stack_a, ps->stack_a->min);
		if (min_a_pos != 0)
			*cost += count_min_rotate_to_top(ps->stack_a, ps->stack_a->min);
	}
	else
	{
		num_just_higher = ft_next_higher_num(ps->stack_a, num_to_push);
		num_just_higher_pos = find_position(ps->stack_a, num_just_higher);
		if (num_just_higher_pos != 0)
			*cost += count_min_rotate_to_top(ps->stack_a, num_just_higher);
	}
}

static void	calculate_cost_b(t_push_swap *ps, int num_to_push, int *cost)
{
	int	num_pos_in_b;

	num_pos_in_b = find_position(ps->stack_b, num_to_push);
	if (num_pos_in_b != 0)
	{
		if (num_pos_in_b <= ps->stack_b->size / 2)
			*cost += num_pos_in_b;
		else
			*cost += ps->stack_b->size - num_pos_in_b;
	}
}

static int	calculate_cost_to_push(t_push_swap *ps, int num_to_push)
{
	int	cost;

	cost = 1;
	calculate_cost_a(ps, num_to_push, &cost);
	calculate_cost_b(ps, num_to_push, &cost);
	return (cost);
}

int	find_min_cost_number(t_push_swap *ps)
{
	int				min_cost;
	int				num_to_push;
	int				cost;
	t_stack_node	*tmp;

	min_cost = INT_MAX;
	num_to_push = 0;
	tmp = ps->stack_b->top_node;
	while (tmp != NULL)
	{
		cost = calculate_cost_to_push(ps, tmp->value);
		if (cost == 1)
			return (tmp->value);
		if (cost < min_cost)
		{
			min_cost = cost;
			num_to_push = tmp->value;
		}
		tmp = tmp->next;
	}
	return (num_to_push);
}
