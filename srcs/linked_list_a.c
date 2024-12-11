/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:48:42 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/11 16:54:33 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_a	*create_stack_a(int argc, char **argv)
{
	t_stack_a	*head_a;
	t_stack_a	*tmp;
	int			i;

	i = 1;
	head_a = ft_newnode_a(ft_atoi(argv[i]));
	tmp = head_a;
	while (++i < argc)
	{
		tmp->next = ft_newnode_a(ft_atoi(argv[i]));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	return (head_a);
}

t_stack_a	*ft_newnode_a(int content)
{
	t_stack_a	*node_a;

	node_a = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (!node_a)
		return (NULL);
	node_a->content = content;
	node_a->next = NULL;
	return (node_a);
}

void	ft_clearnode_a(t_stack_a **head_a)
{
	t_stack_a	*tmp;

	while (*head_a != NULL)
	{
		tmp = *head_a;
		*head_a = tmp->next;
		free(tmp);
	}
}

int	ft_lstsize_a(t_stack_a *head_a)
{
	int	i;

	i = 0;
	while (head_a != NULL)
	{
		i++;
		head_a = head_a->next;
	}
	return (i);
}

void	new_content_a(t_stacks *stacks)
{
	int 		size;
	int 		index;
	t_stack_a 	*head_a;

	head_a = stacks->head_a;
	size = ft_lstsize_a(stacks);
	index = 0;
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	while (stacks->head_b->content > head_a->content)
	{
		index++;
		head_a = head_a->next;
	}
	if (index > size / 2)
		stacks->moves->ra = index;
	else
		stacks->moves->rra = size - index;
	apply_moves_new_a(stacks);	
}
