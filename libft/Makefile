# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeonscho <jeonscho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/12 16:37:15 by jeonscho          #+#    #+#              #
#    Updated: 2023/01/16 19:49:10 by jeonscho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# define

NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
HEADER	= libft.h -I./gnl -I./printf/includes
AR		= ar -crs
RM		= rm -f
FILES	= ft_istest.c ft_str.c ft_memcontrol.c ft_switch.c ft_find.c\
		  ft_atoi.c	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
		  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		  ft_atol.c ft_ternary.c ft_isnum.c
FILES_B	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		  ft_lstmap.c
GNL 	= ./gnl/get_next_line.c ./gnl/get_next_line_utils.c 
OBJS	= $(FILES:.c=.o)
OBJS_GNL= $(GNL:.c=.o)
OBJS_BN	= $(FILES_B:.c=.o)

ifdef BN
	OBJS += $(OBJS_BN)
else
	
endif

# colors

GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHITE		:=	\033[1;37m
EOC			:=	\033[1;0m

# rules

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_GNL)
		@echo "$(GREEN)---------------$(EOC)"
		@$(MAKE) -C ./printf
		@mv ./printf/libftprintf.a $@
		@$(AR) $@ $^
		@echo "$(GREEN)GNL done.$(EOC)"
		@echo "$(GREEN)Libft done.$(EOC)"
		@echo "$(GREEN)---------------$(EOC)"

%.o: %.c
		@$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

bonus:	
		@echo "$(WHITE)Bonus of libft have added.$(EOC)"
		@make BN=1 all

clean:
		@$(MAKE) clean -C ./printf
		@$(RM) $(OBJS) $(OBJS_BN) $(OBJS_GNL)
		@echo "$(RED)cleaning object files.$(EOC)"

fclean:	clean
		@$(RM) $(NAME)
		@echo "$(RED)clean up the object files and libft.a!$(EOC)"

re:	
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all bonus clean fclean re
