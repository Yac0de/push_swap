/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_both.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:31:47 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/21 13:33:55 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, "");
	swap(stack_b, "");
	write(1, "ss\n", 3);
	stack_a->count_moove++;
	stack_b->count_moove++;
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, "");
	rotate(stack_b, "");
	write(1, "rr\n", 3);
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, "");
	reverse_rotate(stack_b, "");
	write(1, "rrr\n", 4);
	stack_a->count_moove++;
	stack_b->count_moove++;
}
