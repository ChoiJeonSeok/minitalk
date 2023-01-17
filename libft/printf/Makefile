# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 17:03:56 by jeonscho          #+#    #+#              #
#    Updated: 2023/01/16 19:44:05 by jeonscho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
AR		=	ar -crs
RM		=	rm -f
HEADER	=	-I./includes
SRCS	=	ft_printf.c	srcs/ft_specifier_c.c	srcs/ft_specifier_d.c\
			srcs/ft_specifier_p.c	srcs/ft_specifier_percent.c\
			srcs/ft_specifier_s.c	srcs/ft_specifier_u.c\
			srcs/ft_specifier_upperx.c	srcs/ft_specifier_x.c\
			srcs/ft_strchr_i.c srcs/ft_putchar_i.c srcs/ft_putstr_i.c\
			srcs/ft_utoa_base.c srcs/ft_itoa_printf.c srcs/ft_strlen_printf.c
OBJS	=	$(SRCS:.c=.o)

# colors

GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHIET		:=	\033[1;37m
EOC			:=	\033[1;0m

# rules

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(AR) $@ $^
	@echo "$(GREEN)ft_printf done.$(EOC)"

%.o:	%.c
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)cleaning object files of ft_printf$(EOC)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(RED)cleaning object files and libftprintf.a$(EOC)"

re: 
	@$(MAKE) fclean 
	@$(MAKE) all

.PHONY: all clean fclean re
