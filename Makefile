##------------------------------------------------------------------##
# Variables.

## Name
NAME-PS				= push_swap
NAME-LIBFT			= ./lib/libft.a

## Compiler, flags, & other commands
CC 					= cc
CFLAGS 				= -g -Wall -Werror -Wextra -I
AR					= ar rcs
RM					= rm -f

## Sources & header
SRC-PS				= ./src/push_swap.c \
						./src/algo_radixsort.c \
						./src/algo_simplesort.c \
						./src/algo_simplesort_sort3.c \
						./src/operations_push.c \
						./src/operations_rotaterev.c \
						./src/operations_rotate.c \
						./src/operations_swap.c \
						./src/utils_check.c \
						./src/utils_free+print.c \
						./src/utils_index.c \
						./src/utils_lists.c

HEADER				= ./src/

## Text colors
RED					=	\033[1;31m
GREEN				=	\033[1;32m
COLOFF				=	\033[0m

##------------------------------------------------------------------##
# Build rules

all:				$(NAME-LIBFT) $(NAME-PS)

#bonus:				$(NAME-LIBFT) $(NAME-CLIENTB) $(NAME-SERVERB)

clean:
					@$(RM) $(NAME-PS)
					@echo "$(RED)Push Swap's gone, baby, gone!$(COLOFF)"

fclean:				clean
					@make fclean -C ./lib
					@echo "$(RED)Libft's gone, baby, gone!$(COLOFF)"

re:					fclean all

re-bonus:			fclean bonus

##------------------------------------------------------------------##
# Targets
$(NAME-LIBFT):
		@make -C./lib
		@echo "$(GREEN)Libft ready!$(COLOFF)"

$(NAME-PS): ./src/push_swap.c $(NAME-LIBFT)
		@$(CC) $(CFLAGS) $(HEADER) $(SRC-PS) $(NAME-LIBFT) -o $(NAME-PS)
		@echo "$(GREEN)Push Swap ready!$(COLOFF)"

##------------------------------------------------------------------##
#.PHONY
.PHONY: clean fclean all re
