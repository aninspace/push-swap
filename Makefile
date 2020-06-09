# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/12 18:12:32 by anastasiase       #+#    #+#              #
#    Updated: 2020/06/09 12:29:48 by anastasiase      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIB 		= libft/libft.a

HEADER_NAME		= push_swap.h
NAME_PS 		= push_swap
NAME_CHECK 		= checker

INC_DIR 		= ./includes/
INC_LIB_FT 		= ./libft
SRC_DIR 		= ./sources/
OBJ_DIR 		= ./obj/

SRC_NAME_PS		= push_swap.c \
				  choose_instruction.c \
				  common_sort.c \
				  init.c \
				  parse.c \
				  stack.c \
				  sorting.c \
				  tools.c \
				  instructions.c \

SRC_NAME_CHECK	= checker.c \
				  choose_instruction.c \
				  common_sort.c \
				  init.c \
				  parse.c \
				  stack.c \
				  sorting.c \
				  tools.c \
				  instructions.c \

HEADER 			= $(addprefix $(INC_DIR), $(HEADER_NAME))

SRC_PS			= $(addprefix $(SRC_PATH), $(SRC_NAME_PS))
SRC_CHECK		= $(addprefix $(SRC_PATH), $(SRC_NAME_CHECK))
OBJ_PS			= $(addprefix $(OBJ_DIR), $(SRC_NAME_PS:.c=.o))
OBJ_CHECK		= $(addprefix $(OBJ_DIR), $(SRC_NAME_CHECK:.c=.o))

CC				= gcc
FLAGS			= -Wall -Wextra -Werror
GCC_LIBFT 		= -L ./libft -l ft

all: $(NAME_PS) $(NAME_CHECK)

$(NAME_PS): $(OBJ_DIR) $(OBJ_PS) $(NAME_LIB) $(HEADER)
	$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_PS) $(FLAGS) -o $(NAME_PS)

$(NAME_CHECK): $(OBJ_DIR) $(OBJ_CHECK) $(NAME_LIB) $(HEADER)
	$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_CHECK) $(FLAGS) -o $(NAME_CHECK)

$(OBJ_DIR):
	@mkdir -p obj

$(NAME_LIB):
	@make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) -c -I $(INC_DIR) -I $(INC_LIB_FT) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME_PS) $(NAME_CHECK)
	@make fclean -C libft/

re: fclean all