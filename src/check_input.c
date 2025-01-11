/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:03:58 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/26 14:17:42 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	print_error_with_arg(const char *message, const char *arg)
{
	char	buffer[1024];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (message[i])
		buffer[j++] = message[i++];
	i = 0;
	while (arg && arg[i])
		buffer[j++] = arg[i++];
	buffer[j++] = '\n';
	buffer[j] = '\0';
	return (ft_putstr_fd(buffer, 2), 2);
}

static int	ft_isint(const char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		print_error_with_arg("Value exceeds the capacity"
			" of the specified data type : ", str);
		return (0);
	}
	return (1);
}

static int	is_unique(char **argv, char *num, int i)
{
	int	j;

	j = 1;
	while (argv[j] && j < i)
	{
		if (ft_atoi(argv[j]) == ft_atoi(num))
		{
			ft_putstr_fd("Error\n", 2);
			print_error_with_arg("Value is not unique : ", argv[i]);
			return (0);
		}
		j++;
	}
	return (1);
}

static int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("Error\nInvalid input: NULL pointer received\n", 2);
		return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && (str[0] != '-') && (str[0] != '+'))
		{
			print_error_with_arg("Error\nValue is not a digit : ", str);
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_input(int argc, char **argv, int is_allocated)
{
	int	i;

	i = 1;
	if (argc == 2)
		i = 0;
	if (argc < 2)
		exit(EXIT_FAILURE);
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]) || !ft_isint(argv[i]) || !is_unique(argv,
				argv[i], i))
		{
			if (is_allocated && argv)
				free_argv(argv);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
