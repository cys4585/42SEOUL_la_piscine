# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 18:35:35 by youngcho          #+#    #+#              #
#    Updated: 2022/05/19 16:26:18 by youngcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = srcs/
OBJ_DIR = objs/
SRCS_NAME = ft_printf.c \
		handle_cs5.c \
		handle_di.c \
		handle_uxx.c \
		handle_p.c
SRCS = $(addprefix $(SRC_DIR), $(SRCS_NAME))
OBJS = $(addprefix $(OBJ_DIR), $(SRCS_NAME:%.c=%.o))
INC = inc/

LIBFT_DIR = libft/
LIBFT_NAME = $(LIBFT_DIR)libft.a

AR = ar
ARFLAGS = rcsu
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re
all : $(NAME)
clean :
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)
fclean :
	make fclean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)
re : fclean
	make all
	
$(NAME) : $(LIBFT_NAME) $(OBJ_DIR) $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(LIBFT_NAME) :
	make all -C $(LIBFT_DIR)
	cp $(LIBFT_NAME) $(NAME)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

