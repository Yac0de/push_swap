/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:34:14 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/26 10:13:42 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack *stack)
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

void	free_argv(char **argv)
{
	char	**tmp;

	**tmp = argv;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(argv);
}

void	free_stack_and_argv(t_stack *stack_a, t_stack *stack_b, char **argv,
		int is_allocated)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	if (is_allocated && argv)
		free_argv(argv);
}
