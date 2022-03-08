# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 17:05:55 by sgmira            #+#    #+#              #
#    Updated: 2022/03/07 18:57:37 by sgmira           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

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

SRCS1 = pipex_bonus.c \
		find_path_bonus.c \
		get_path_bonus.c \
		split_bonus.c \
		main_bonus.c	\
		free_bonus.c \
		get_error_bonus.c \
		get_error2_bonus.c \
		arg_no_err_bonus.c \
		ft_strcmp_bonus.c \
		ft_strdup_bonus.c \
		ft_putstr_fd_bonus.c \
		ft_strtrim_bonus.c \
		get_next_line_utils_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS1 = $(SRCS1:.c=.o)


all: $(NAME)

$(NAME): $(OBJS) 
	@$(RM) $(OBJS1) $(NAME)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

bonus: $(OBJS1)
	@$(RM) $(OBJS) $(NAME)
	$(CC) $(CFLAGS) $(SRCS1) -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS1)    

fclean: clean
	$(RM) $(NAME)

re: fclean all