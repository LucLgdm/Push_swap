/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:12:55 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/10 11:49:48 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

# define INTMAX 2147483647
# define INTMIN -2147483648

// Structures
    // Linked list
struct s_stack_a
{
	int		        	content;
	struct s_stack_a	*next;
};
typedef struct s_stack_a t_stack_a;

struct s_stack_b
{
	int		        	content;
	struct s_stack_b	*next;
};
typedef struct s_stack_b t_stack_b;

struct s_stacks
{
    t_stack_a   *head_a;
    t_stack_b   *head_b;
    
};
typedef struct s_stacks t_stacks;

// Error handling
void    error_input(int argc, char **argv);
void    check_integer(int argc, char **argv);
void    check_int_size(int argc, char **argv);
void    print_error_and_exit(char *str);

// Linked list a
t_stack_a   *create_stack_a(int argc, char **argv);

#endif


/********************************************
 * Authorized function :                    *
 * read                                     *
 * write                                    *
 * malloc                                   *
 * free                                     *
 * exit                                     *
*********************************************/