# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 12:24:12 by lde-merc          #+#    #+#              #
#    Updated: 2024/12/05 15:54:58 by lde-merc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT = libft/libft.a
SRC_DIR = srcs
OBJ_DIR = objs
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INCLUDES = includes/

all: makelibft $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(OBJ) -Llibft -lft -o $(NAME)
		@echo "Creation of the executable $(NAME)"
		
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ -I $(INCLUDES)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean
	@echo "Cleaning of the object directory $(OBJ_DIR) and libft"
	
fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@echo "Cleaning of the executable $(NAME) and the library $(LIBFT)"
	
re: fclean all
	
makelibft:
	make -C libft all

.PHONY: all clean fclean re makelibft