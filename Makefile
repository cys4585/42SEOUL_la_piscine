# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 18:35:35 by youngcho          #+#    #+#              #
#    Updated: 2022/05/17 19:14:30 by youngcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = ./libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c \
		handle_cs5.c \
		handle_diu.c
OBJS = $(SRCS:.c=.o)

AR = ar
ARFLAGS = rcsu
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.PHONY : all clean fclean re
all : $(NAME)
clean :
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
fclean :
	make fclean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
	$(RM) $(NAME)
re : fclean
	make all
	
$(NAME) : $(OBJS) $(LIBFT_NAME)
	$(AR) $(ARFLAGS) $@ $<

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_NAME) :
	make all -C $(LIBFT_DIR)
	cp $(LIBFT_NAME) $(NAME)
