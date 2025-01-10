/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:43:27 by ymeziane          #+#    #+#             */
/*   Updated: 2023/12/27 15:46:38 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	print_error_with_arg_b(const char *message, const char *arg)
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

static int	ft_isint_b(const char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		print_error_with_arg_b("Value exceeds the capacity"
			" of the specified data type : ", str);
		return (0);
	}
	return (1);
}

static int	is_unique_b(char **argv, char *num, int i)
{
	int	j;

	j = 1;
	while (argv[j] && j < i)
	{
		if (ft_atoi(argv[j]) == ft_atoi(num))
		{
			ft_putstr_fd("Error\n", 2);
			print_error_with_arg_b("Value is not unique : ", argv[i]);
			return (0);
		}
		j++;
	}
	return (1);
}

static int	ft_isnumber_b(char *str)
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
			print_error_with_arg_b("Error\nValue is not a digit : ", str);
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_input_b(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 2)
		i = 0;
	if (argc < 2)
		exit(EXIT_FAILURE);
	while (argv[i])
	{
		if (!ft_isnumber_b(argv[i]) || !ft_isint_b(argv[i])
			|| !is_unique_b(argv, argv[i], i))
			exit(EXIT_FAILURE);
		i++;
	}
}
