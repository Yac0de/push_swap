# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 20:00:46 by ymeziane          #+#    #+#              #
#    Updated: 2023/12/27 14:38:37 by ymeziane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
NC=\033[0m

NAME = push_swap
BONUS_NAME = checker
CC = cc
FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./inc -I./libft/inc

LIBFT = libft/libft.a
LIBFT_DIR = libft

SRC_DIR = src
SRC_BONUS_DIR = src_bonus
OBJ_DIR = obj
OBJ_BONUS_DIR = obj_bonus

SRC_FILES = main check_input turk_sort update_stacks ft_stack presort \
            instructions_simple instructions_both utils count_rotate min_cost_num \
            move free
BONUS_SRC_FILES = main check_input instructions_both instructions_simple ft_stack free handle_input_instructions end_message

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
BONUS_SRC = $(addprefix $(SRC_BONUS_DIR)/, $(addsuffix _bonus.c, $(BONUS_SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))
BONUS_OBJ = $(addprefix $(OBJ_BONUS_DIR)/, $(addsuffix _bonus.o, $(BONUS_SRC_FILES)))

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "${GREEN}Creating executable $(NAME)${NC}"
	@$(CC) $(OBJ) $(LIBFT) -o $@

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT)
	@echo "${GREEN}Creating executable $(BONUS_NAME)${NC}"
	@$(CC) $(BONUS_OBJ) $(LIBFT) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "${YELLOW}Compiling $<${NC}"
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	@echo "${YELLOW}Compiling $<${NC}"
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "${GREEN}Making libft${NC}"
	@echo "${YELLOW}Entering libft directory${NC}"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "${YELLOW}Leaving libft directory${NC}"

clean:
	@echo "${RED}Cleaning object files${NC}"
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@echo "${YELLOW}Entering libft directory for cleaning${NC}"
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@echo "${YELLOW}Leaving libft directory${NC}"

fclean: 
	@echo "${RED}Cleaning object files${NC}"
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@echo "${RED}Removing executable $(NAME) and $(BONUS_NAME)${NC}"
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "${YELLOW}Entering libft directory for full clean${NC}"
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "${YELLOW}Leaving libft directory${NC}"

re: fclean all

.PHONY: all clean fclean re bonus


