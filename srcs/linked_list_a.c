/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:48:42 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/10 12:02:47 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_a   *create_stack_a(int argc, char **argv)
{
    t_stack_a   *head_a;
    t_stack_a   *tmp;
    int         i;
    
    head_a = ft_lstnew(argv[1]);
    tmp = head_a;
    i = 1;
    while (++i < argc)
    {
        tmp->next = ft_lstnew(ft_atoi(argv[i]));
        tmp = tmp->next;
        tmp->next = NULL;
    }
    return (head_a);
}
