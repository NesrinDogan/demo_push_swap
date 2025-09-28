NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --no-print-directory

LIBFT_DIR	= libft

LIBFT	= $(LIBFT_DIR)/libft.a

# Klasörler
UTILS = utils
OPERATIONS = operations
PARSING = parsing
SORTING = sorting

# Tüm kaynak dosyalar
SRC = push_swap.c \
	  $(UTILS)/stack_utils.c \
	  $(UTILS)/free_utils.c \
	  $(UTILS)/error.c \
	  $(OPERATIONS)/sa.c \
	  $(OPERATIONS)/sb.c \
	  $(OPERATIONS)/ss.c \
	  $(OPERATIONS)/pa.c \
	  $(OPERATIONS)/pb.c \
	  $(OPERATIONS)/ra.c \
	  $(OPERATIONS)/rb.c \
	  $(OPERATIONS)/rr.c \
	  $(OPERATIONS)/rra.c \
	  $(OPERATIONS)/rrb.c \
	  $(OPERATIONS)/rrr.c \
	  $(PARSING)/ft_atol.c \
	  $(PARSING)/check_errors.c \
	  $(PARSING)/parse_args.c \
	  $(SORTING)/sort_three.c \
	  $(SORTING)/sort_up_to_six.c \
	  $(SORTING)/index_stack.c \
	  $(SORTING)/radix_sort.c

OBJ = $(SRC:.c=.o)

# Derleme kuralları
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
