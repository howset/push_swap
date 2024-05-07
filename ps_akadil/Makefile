NAME		=	push_swap
B_NAME		=	checker
SRC_DIR		=	srcs
SRCS		= 	main.c parse/ft_parse.c part1/ft_part1_median.c part2/ft_part2_cost.c \
				commands/ft_commands_1.c commands/ft_commands_2.c commands/ft_commands_3.c \
				utils/ft_stack_init.c utils/ft_free_and_error_1.c utils/ft_free_and_error_2.c \
				parse/ft_parse_check_int.c parse/ft_parse_check.c parse/ft_parse_createB.c \
				parse/ft_parse_utils.c part1/ft_quicksort.c part1/ft_part1_utils.c \
				part2/ft_part2_find_cost.c part2/ft_part2_find_cost_seperated.c \
				part2/ft_part2_operation.c part2/ft_part2_operation_seperated.c \
				part2/ft_part2_stabilizer.c utils/ft_is_sorted.c

B_SRCS		=	bonus/ft_bonus.c bonus/ft_bonus_utils_1.c bonus/ft_bonus_utils_2.c bonus/get_next_line.c parse/ft_parse.c \
				commands/ft_commands_1.c commands/ft_commands_2.c commands/ft_commands_3.c \
				utils/ft_stack_init.c utils/ft_free_and_error_1.c utils/ft_free_and_error_2.c \
				bonus/get_next_line_utils.c parse/ft_parse_check_int.c parse/ft_parse_utils.c \
				parse/ft_parse_check.c parse/ft_parse_createB.c utils/ft_is_sorted.c 

CFLAGS		= -g -Wall -Werror -Wextra
CC			= cc
BUILD_DIR 	= .build
INCLUDES	= headers
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
B_SRCS		:= $(B_SRCS:%=$(SRC_DIR)/%)
OBJS		= $(SRCS:%.c=$(BUILD_DIR)/%.o)
B_OBJS		= $(B_SRCS:%.c=$(BUILD_DIR)/%.o)

all			: ${NAME}

${NAME}		: ${OBJS}
		make -C libft
		${CC} $(OBJS) -o $(NAME) -L./libft/ -lft

bonus		: ${B_NAME}

${B_NAME}	: ${B_OBJS}
		${CC} ${B_OBJS} -o ${B_NAME} -L./libft/ -lft

${BUILD_DIR}/%.o:%.c
		${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

clean :
		make -C ./libft/ clean
		rm -rf ${OBJS} ${B_OBJS}

fclean : clean
		rm -rf ${NAME} ${B_NAME} libft/libft.a

re : fclean all

.PHONY : all bonus clean fclean re