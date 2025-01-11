/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:57:47 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/28 16:28:00 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	init_stacks(t_push_swap *ps)
{
	ps->stack_a = malloc(sizeof(t_stack));
	if (ps->stack_a == NULL)
		return ;
	ps->stack_a->size = 0;
	ps->stack_a->min = INT_MAX;
	ps->stack_a->max = INT_MIN;
	ps->stack_a->top_node = NULL;
	ps->stack_b = malloc(sizeof(t_stack));
	if (ps->stack_b == NULL)
		return ;
	ps->stack_b->size = 0;
	ps->stack_b->min = INT_MAX;
	ps->stack_b->max = INT_MIN;
	ps->stack_a->count_moove = 0;
	ps->stack_b->count_moove = 0;
	ps->stack_b->top_node = NULL;
}

static int	ft_arraylen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static void	fill_stack_a(t_push_swap *ps, int argc, char **argv,
			int is_allocated)
{
	int	i;
	int	*num;

	i = 1;
	if (argc == 2)
	{
		argc = ft_arraylen(argv);
		i = 0;
	}
	while (i < argc)
	{
		num = malloc(sizeof(int));
		if (!num)
		{
			ft_printf("Error\nAllocation failed\n");
			free_stack_and_argv(ps->stack_a, ps->stack_b, argv, is_allocated);
			exit(EXIT_FAILURE);
		}
		*num = ft_atoi(argv[i]);
		ft_stackadd_back(ps->stack_a, ft_stacknew(*num));
		free(num);
		i++;
	}
}

static int	is_sorted(t_stack *stack)
{
	t_stack_node	*current;

	current = stack->top_node;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;
	t_context	ctx;
	int			is_allocated;

	is_allocated = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		is_allocated = 1;
	}
	ctx.argv = argv;
	ctx.is_allocated = is_allocated;
	check_input(argc, argv, is_allocated);
	init_stacks(&push_swap);
	fill_stack_a(&push_swap, argc, argv, is_allocated);
	if (is_sorted(push_swap.stack_a))
		return (free_stack_and_argv(push_swap.stack_a, push_swap.stack_b,
				argv, is_allocated), 0);
	turk_sort(&push_swap, &ctx);
	return (free_stack_and_argv(push_swap.stack_a, push_swap.stack_b,
			argv, is_allocated), 0);
}
