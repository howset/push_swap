##------------------------------------------------------------------##
# Variables.

## Name
NAME-PS				= push_swap
NAME-LIBFT			= ./lib/libft.a

## Compiler, flags, & other commands
CC 					= cc
CFLAGS 				= -Wall -Werror -Wextra -I
AR					= ar rcs
RM					= rm -f

## Sources & header
SRC-PS				= ./src/push_swaps.c \
						./src/algo_radixsorts.c \
						./src/algo_simplesorts.c \
						./src/operations_pushs.c \
						./src/operations_rotaterevs.c \
						./src/operations_rotates.c \
						./src/operations_swaps.c \
						./src/utils_checkss.c \
						./src/utils_free+prints.c \
						./src/utils_indexs.c \
						./src/utils_listss.c \
						./src/utils_others.c

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

$(NAME-PS): ./src/push_swaps.c $(NAME-LIBFT)
		@$(CC) $(CFLAGS) $(HEADER) $(SRC-PS) $(NAME-LIBFT) -o $(NAME-PS)
		@echo "$(GREEN)Push Swap ready!$(COLOFF)"

##------------------------------------------------------------------##
#.PHONY
.PHONY: clean fclean all re
