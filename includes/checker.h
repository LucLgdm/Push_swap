/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:50:43 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/18 14:37:03 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stdio.h"
# include "../libft/libft.h"

struct	s_stack_a
{
	int					content;
	struct s_stack_a	*next;
};
typedef struct s_stack_a	t_stack_a;

struct	s_stack_b
{
	int					content;
	struct s_stack_b	*next;
};
typedef struct s_stack_b	t_stack_b;

struct	s_stacks
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;
};
typedef struct s_stacks		t_stacks;

// Error handling
void		error_input(int argc, char **argv, int flag);
void		check_integer(int argc, char **argv, int flag);
void		check_int_size(int argc, char **argv, int flag);
void		doppel_check(t_stack_a *head_a);

// Linked list a
t_stack_a	*create_stack_a(char **argv, int flag);
t_stack_a	*ft_newnode_a(int content);
void		ft_clearnode_a(t_stack_a **head_a);
int			ft_lstsize_a(t_stack_a *head_a);
bool		is_sorted(t_stacks *stacks);

// Linked list b
void		ft_clearnode_b(t_stack_b **head_b);
int			ft_lstsize_b(t_stack_b *head_b);

// Commande swap
void		ft_swap(t_stacks *stacks, char c);
void		swap_a(t_stack_a *head_a, int n);
void		swap_b(t_stack_b *head_b, int n);

// Commande rotate
void		ft_rotate(t_stacks *stacks, char c);
void		rotate_a(t_stacks *stacks, t_stack_a *head_a, int n);
void		rotate_b(t_stacks *stacks, t_stack_b *head_b, int n);

// Commande reverse rotate
void		ft_rev_rotate(t_stacks *stacks, char c);
void		rev_rotate_a(t_stacks *stacks, int n);
void		rev_rotate_b(t_stacks *stacks, int n);

// Commande push
void		ft_push(t_stacks *stacks, char c);
void		ft_last_push_a(t_stacks *stacks);
void		ft_push_a(t_stacks *stacks);
void		ft_first_push_b(t_stacks *stacks);
void		ft_push_b(t_stacks *stacks);

// Executing
void		execute(t_stacks *stacks);
void		exec_com(t_stacks *stacks, char *com);

// Print
void		print_error_and_exit(void);

// Free
void		free_all(t_stacks *stacks);
void		free_and_exit(t_stacks *stacks, char *com);

#endif