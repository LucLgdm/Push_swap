/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:36:27 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/18 14:36:45 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_input(int argc, char **argv, int flag)
{
	int	i;

	if (argc == 1)
		exit(EXIT_FAILURE);
	if (flag != 0)
	{
		i = 0;
		while (argv[i])
			i++;
		check_integer(i, argv, flag);
		check_int_size(i, argv, flag);
	}
	else
	{
		check_integer(argc, argv, flag);
		check_int_size(argc, argv, flag);
	}
}

void	check_int_size(int argc, char **argv, int flag)
{
	int		i;
	long	num;

	i = 0;
	if (flag != 0)
		i--;
	while (++i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INTMAX || num < INTMIN)
			print_error_and_exit();
	}
}

void	check_integer(int argc, char **argv, int flag)
{
	int	i;
	int	j;

	i = 0;
	if (flag != 0)
		i--;
	while (++i < argc)
	{
		j = -1;
		if (argv[i][0] == '\0')
			print_error_and_exit();
		while (++j < (int)ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (j == 0 && ft_strlen(argv[i]) != 1 && (argv[i][j] == '-'
					|| argv[i][j] == '+'))
				{
					j++;
					continue ;
				}
				print_error_and_exit();
			}
		}
	}
}

void	print_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	doppel_check(t_stack_a *head_a)
{
	t_stack_a	*tmp;
	t_stack_a	*ptr;
	int			n;

	ptr = head_a;
	while (ptr != NULL)
	{
		tmp = ptr;
		n = tmp->content;
		tmp = tmp->next;
		while (tmp != NULL)
		{
			if (n == tmp->content)
			{
				ft_putstr_fd("Error\n", 2);
				ft_clearnode_a(&head_a);
				exit(EXIT_FAILURE);
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}
