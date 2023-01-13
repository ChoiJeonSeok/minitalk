# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 18:47:59 by jeonscho          #+#    #+#              #
#    Updated: 2023/01/13 22:18:09 by jeonscho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# define

NAME	= minitalk
C_AND_S	= server client
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
LIBFT	= ./libft/libft.a
HEADER	= -I./includes -I./libft
AR		= ar -crs
RM		= rm -f
SRCS	= srcs/server.c srcs/client.c
OBJS	= $(SRCS:.c=.o)

# color

GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHITE		:=	\033[1;37m
EOC			:=	\033[1;0m

# rules

all: $(NAME)

$(NAME): $(LIBFT) $(C_AND_S)

$(LIBFT):
		@$(MAKE) -C ./libft

client:	$(LIBFT)
		@$(CC) $(CFLAGS) $(HEADER) ./srcs/client.c -lft -L./libft -o $@
		@echo "$(GREEN)Client compiled.$(EOC)"

server:	$(LIBFT)
		@$(CC) $(CFLAGS) $(HEADER) ./srcs/server.c -lft -L./libft -o $@
		@echo "$(GREEN)Server compiled.$(EOC)"

clean:
		@$(MAKE) clean -C ./libft
		@$(RM) $(OBJS)
		@echo "$(GREEN)clean object files.$(EOC)"

fclean:	clean
		@$(RM) $(C_AND_S)
		@$(RM) $(LIBFT)
		@echo "$(GREEN)clean up!$(EOC)"

re:	fclean all

.PHONY: all bonus clean fclean re
