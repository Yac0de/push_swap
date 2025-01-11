/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:34:14 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/27 15:45:22 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack_b(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	current = stack->top_node;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

void	free_argv_b(char **argv)
{
	char	**tmp;

	tmp = argv;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(argv);
}

void	free_stack_and_argv_b(t_stack *stack_a, t_stack *stack_b,
		char **argv, int is_allocated)
{
	if (stack_a)
		free_stack_b(stack_a);
	if (stack_b)
		free_stack_b(stack_b);
	if (is_allocated && argv)
		free_argv_b(argv);
}
