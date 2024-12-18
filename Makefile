# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 12:24:12 by lde-merc          #+#    #+#              #
#    Updated: 2024/12/18 11:03:11 by lde-merc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT = libft/libft.a
SRC_DIR = srcs
OBJ_DIR = objs
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
SRC_DIR_BONUS = bonus
OBJ_DIR_BONUS = objs_bonus
SRC_BONUS = $(wildcard $(SRC_DIR_BONUS)/*.c)
OBJ_BONUS = $(SRC_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

INCLUDES = includes/

all: makelibft $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)
		@echo "Creation of the executable $(NAME)"
		
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

bonus: all $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAG) $(OBJ_BONUS) -Llibft -lft -o $(NAME_BONUS)
	@echo "Creation of the executable $(NAME_BONUS)"

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)
	
clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@make -C libft clean
	@echo "Cleaning of the object directory $(OBJ_DIR), $(OBJ_DIR_BONUS) and libft"
	
fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f $(LIBFT)
	@echo "Cleaning of the executables $(NAME), $(NAME_BONUS) and the library $(LIBFT)"
	
re: fclean all
	
makelibft:
	make -C libft all

.PHONY: all clean fclean re makelibft bonus