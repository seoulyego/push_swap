# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 18:41:36 by yeongo            #+#    #+#              #
#    Updated: 2023/01/03 06:24:21 by yeongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MANDATORY	:=	push_swap
NAME_BONUS		:=	checker

LIBFT			:=	./libft/libft.a
LIBFT_DIR		:=	./libft/
LIBFT_HEADER	:=	./libft/include
LDFLAGS			:=	-L$(LIBFT_DIR)
LDLIBS			:=	-lft

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror
CPPFLAGS		:=	-I$(LIBFT_HEADER)
RM				:=	rm -rf

HEADER			:=	./include/
SRC_DIR			:=	./src/
OBJ_DIR			:=	./.obj/

HEADER_BONUS	:=	./bonus/include/
SRC_B_DIR		:=	./bonus/src/
OBJ_B_DIR		:=	./bonus/.obj/

SRC_FILES		:=	$(addsuffix .c,			\
					operate					\
					push					\
					reverse_rotate			\
					rotate					\
					stack					\
					swap					\
					print_result			\
					parse_args				\
					parse_util				\
					push_swap				\
					)
OBJ_FILES		:=	$(SRC_FILES:.c=.o)
SRC				:=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRC_B_FILES		:=	$(addsuffix .c,			\
					checker_bonus			\
					operate_bonus			\
					parse_args_bonus		\
					parse_util_bonus		\
					print_result_bonus		\
					push_bonus				\
					reverse_rotate_bonus	\
					rotate_bonus			\
					stack_bonus				\
					swap_bonus				\
					)
OBJ_B_FILES		:=	$(SRC_B_FILES:.c=.o)
SRC_BONUS		:=	$(addprefix $(SRC_B_DIR), $(SRC_B_FILES))
OBJ_BONUS		:=	$(addprefix $(OBJ_B_DIR), $(OBJ_B_FILES))

ifdef BONUS
		CPPFLAGS		+=	-I$(HEADER_BONUS)
		SRC_FOLDER		:=	$(SRC_B_DIR)
		OBJ_FOLDER		:=	$(OBJ_B_DIR)
		OBJS			:=	$(OBJ_BONUS)
		NAME			:=	$(NAME_BONUS)
		PRINT			:=	CHECKER
else
		CPPFLAGS		+=	-I$(HEADER)
		SRC_FOLDER		:=	$(SRC_DIR)
		OBJ_FOLDER		:=	$(OBJ_DIR)
		OBJS			:=	$(OBJ)
		NAME			:=	$(NAME_MANDATORY)
		PRINT			:=	PUSH_SWAP
endif

.PHONY	:	all
all		:	$(OBJ_FOLDER) $(NAME)

$(OBJ_FOLDER)	:
	@if [ ! -d $(OBJ_FOLDER) ]; then \
		mkdir -p $(OBJ_FOLDER); \
	fi

$(NAME)	:	$(OBJS)
	@make -s -C $(LIBFT_DIR) all BINARY_FILE=$(NAME)
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	@echo "\033[01;32m         SUCCESS!        \033[0m"

$(OBJ_FOLDER)%.o	:	$(SRC_FOLDER)%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

.PHONY	:	bonus
bonus	:
	@make BONUS=1 all

.PHONY	:	test
test	:
	@make TEST=1 all

.PHONY	:	clean
clean	:
	@make -s -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR) $(OBJ_B_DIR)
	@echo "\033[91m      REMOVE OBJECT      \033[0m"

.PHONY	:	fclean
fclean	:	clean
	@$(RM) $(LIBFT)
	@$(RM) $(NAME_MANDATORY) $(NAME_BONUS)
	@echo "\033[91m       FCLEAN DONE       \033[0m"

.PHONY	:	re
re		:	fclean
	@make all
