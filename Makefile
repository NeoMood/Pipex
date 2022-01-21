# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 17:05:55 by sgmira            #+#    #+#              #
#    Updated: 2022/01/21 18:14:22 by sgmira           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

CC = cc
CC_FLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f
INCLUDE = pipex.h 

SRCS =  pipex.c \
		find_path.c \
		get_path.c \
		split.c \
		strjoin.c \
		strlen.c \
		main.c	\
		free.c \
		ft_strdup.c \
		get_error.c \
		get_error2.c \
		arg_no_err.c \
		
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)
$(NAME): $(INCLUDE) $(SRCS: .c=.o)

clean:
	$(RM) $(OBJS) 	

fclean: clean
	$(RM) $(NAME)

re: fclean all