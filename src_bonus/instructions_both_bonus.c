/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_both_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:31:47 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/27 15:26:03 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_both_b(t_stack *stack_a, t_stack *stack_b)
{
	swap_b(stack_a);
	swap_b(stack_b);
}

void	rotate_both_b(t_stack *stack_a, t_stack *stack_b)
{
	rotate_b(stack_a);
	rotate_b(stack_b);
}

void	reverse_rotate_both_b(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_b(stack_a);
	reverse_rotate_b(stack_b);
}
