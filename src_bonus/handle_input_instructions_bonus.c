/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_instructions_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:30:38 by ymeziane          #+#    #+#             */
/*   Updated: 2024/01/02 12:14:47 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	error_instructions_b(t_push_swap *push_swap, char *instruction)
{
	ft_putstr_fd("Error\n", 2);
	print_error_with_arg_b("Invalid instruction : ", instruction);
	free_stack_b(push_swap->stack_a);
	free_stack_b(push_swap->stack_b);
	free(instruction);
	exit(EXIT_FAILURE);
}

static void	handle_instruction_b(t_push_swap *push_swap, char *instruction)
{
	if (ft_strncmp(instruction, "rra", 3) == 0)
		reverse_rotate_b(push_swap->stack_a);
	else if (ft_strncmp(instruction, "rrb", 3) == 0)
		reverse_rotate_b(push_swap->stack_b);
	else if (ft_strncmp(instruction, "rrr", 3) == 0)
		reverse_rotate_both_b(push_swap->stack_a, push_swap->stack_b);
	else if (ft_strncmp(instruction, "sa", 2) == 0)
		swap_b(push_swap->stack_a);
	else if (ft_strncmp(instruction, "sb", 2) == 0)
		swap_b(push_swap->stack_b);
	else if (ft_strncmp(instruction, "ss", 2) == 0)
		swap_both_b(push_swap->stack_a, push_swap->stack_b);
	else if (ft_strncmp(instruction, "pa", 2) == 0)
		push_b(push_swap->stack_b, push_swap->stack_a);
	else if (ft_strncmp(instruction, "pb", 2) == 0)
		push_b(push_swap->stack_a, push_swap->stack_b);
	else if (ft_strncmp(instruction, "ra", 2) == 0)
		rotate_b(push_swap->stack_a);
	else if (ft_strncmp(instruction, "rb", 2) == 0)
		rotate_b(push_swap->stack_b);
	else if (ft_strncmp(instruction, "rr", 2) == 0)
		rotate_both_b(push_swap->stack_a, push_swap->stack_b);
	else
		error_instructions_b(push_swap, instruction);
}

void	get_instruction_b(t_push_swap *push_swap)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction != NULL)
	{
		handle_instruction_b(push_swap, instruction);
		free(instruction);
		instruction = get_next_line(0);
	}
	free(instruction);
}
