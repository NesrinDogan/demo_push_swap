#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

/* utils */
t_stack				*stack_new(int value);
void				stack_add_back(t_stack **stack, t_stack *new_node);
int					stack_size(t_stack *stack);
t_stack				*stack_last(t_stack *stack);

/* free & error */
void				free_stack(t_stack **stack);
void				free_split(char **arr);
void				error_msg(void);
void				clean_exit(t_stack *a, char **arr);

/* parsing & control */
t_stack				*parse_args(int argc, char **argv);
int					is_number(char *str);
int					is_duplicate(t_stack *stack, int value);
long				ft_atol(const char *str);
int					is_long(long num);

/* operations */
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

/* sorting */
void				sort_three(t_stack **a);
void				sort_up_to_six(t_stack **a, t_stack **b);
void				index_stack(t_stack *a, int size);
void				radix_sort(t_stack **a, t_stack **b);

#endif
