# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 18:41:36 by yeongo            #+#    #+#              #
#    Updated: 2022/12/05 23:21:24 by yeongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	so_long
CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror
RM				:=	rm -rf

LIBFT			:=	./libft/libft.a
LIBFT_DIR		:=	./libft/
LIBFT_HEADER	:=	./libft/include
LDFAGS			:=	-L$(LIBFT_DIR) -lft

HEADER			:=	./include/
SRC_DIR			:=	./src/
OBJ_DIR			:=	./.obj/

HEADER_BONUS	:=	./bonus/include/
SRC_B_DIR		:=	./bonus/src/
OBJ_B_DIR		:=	./bonus/.obj/

SRC_FILES		:=	$(addsuffix .c,			\
					\
					\
					\
					\
					\
					\
					\
					\
					\
					push_swap)
OBJ_FILES		:=	$(SRC_FILES:.c=.o)
SRC				:=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRC_B_FILES		:=	$(addsuffix .c,			\
					\
					\
					\
					\
					\
					\
					\
					\
					\
					checker_bonus)
OBJ_B_FILES		:=	$(SRC_B_FILES:.c=.o)
SRC_BONUS		:=	$(addprefix $(SRC_B_DIR), $(SRC_B_FILES))
OBJ_BONUS		:=	$(addprefix $(OBJ_B_DIR), $(OBJ_B_FILES))

ifdef BONUS
		INCLUDE			=	$(HEADER_BONUS)
		SRC_FOLDER		=	$(SRC_B_DIR)
		OBJ_FOLDER		=	$(OBJ_B_DIR)
		OBJS			=	$(OBJ_BONUS)
		PRINT			=	BONUS
else
		INCLUDE			=	$(HEADER)
		SRC_FOLDER		=	$(SRC_DIR)
		OBJ_FOLDER		=	$(OBJ_DIR)
		OBJS			=	$(OBJ)
		PRINT			=	SO_LONG
endif

.PHONY	:	all
all		:	$(OBJ_FOLDER) $(NAME)

$(NAME)	:	$(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(LDFAGS) -o $@ $^
	@echo "\033[01;32m       SUCCESS!      \033[0m"

$(OBJ_FOLDER)	:
	@if [ ! -d $(OBJ_FOLDER) ]; then \
		mkdir -p $(OBJ_FOLDER); \
	fi

$(OBJ_FOLDER)%.o	:	$(SRC_FOLDER)%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_HEADER) -I$(INCLUDE) -c -o $@ $<

$(LIBFT)	:
	@make -s -C $(LIBFT_DIR) all

.PHONY	:	bonus
bonus	:
	@make BONUS=1 all

.PHONY	:	clean
clean	:
	@make -s -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR) $(OBJ_B_DIR)
	@echo "\033[91m      REMOVE OBJECT      \033[0m"

.PHONY	:	fclean
fclean	:	clean
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@echo "\033[91m      FCLEAN DONE      \033[0m"

.PHONY	:	re
re		:	fclean
	@make all
