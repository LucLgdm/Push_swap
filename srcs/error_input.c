/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:36:27 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/10 11:45:23 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    error_input(int argc, char **argv)
{
    if (argc == 1)
        exit(EXIT_FAILURE);
    check_integer(argc, argv);
    check_int_size(argc, argv);
}

void    check_int_size(int argc, char **argv)
{
    int     i;
    long    num;

    i = 0;
    while (++i < argc)
    {
        num = ft_atol(argv[i]);
        if (num > INTMAX || num < INTMIN)
            print_error_and_exit("Error in input\nArgument not in range of int\n");
    }
}

void    check_integer(int argc, char **argv)
{
    int	i;
    int j;

	i = 0;
	while (++i < argc)
    {
        j = -1;
        if (argv[i][0] == '\0')
            print_error_and_exit("Error in input\nNon integer input\n");
        while (++j < (int)ft_strlen(argv[i]))
        {
            if (!ft_isdigit(argv[i][j]))
            {
                if (j == 0 && ft_strlen(argv[i]) != 1 && \
                    (argv[i][j] == '-' || argv[i][j] == '+'))
                    {
                        j++;
                        continue;
                    }
                    print_error_and_exit("Error in input\nNon integer input\n");
            }
        }
    }
}

void    print_error_and_exit(char *str)
{
    ft_putstr_fd(str, 2);
    exit(EXIT_FAILURE);
}
