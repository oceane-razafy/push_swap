# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 17:21:40 by orazafy           #+#    #+#              #
#    Updated: 2023/06/11 22:15:39 by orazafy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
IFLAGS = -I$(INCDIR)

SRCDIR = srcs
OBJDIR = objs
BINDIR = bin
INCDIR = include

SRCS_FILES = ft_atoi.c \
		ft_operations_1.c \
		ft_operations_2.c \
		ft_quicksort.c \
		ft_sort_stack_a.c \
		ft_stack_a_to_stack_b.c \
		ft_stack_b_to_stack_a.c \
		ft_two_bigger.c \
		push_swap.c

SRCS = $(addprefix $(SRCDIR)/, $(SRCS_FILES))
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

INCS = $(INCDIR)/push_swap.h

NAME = $(BINDIR)/push_swap

RMR = rm -rf
MKDIR_P = mkdir -p

all: $(NAME)

$(NAME): $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(BINDIR):
	$(MKDIR_P) $(BINDIR)

$(OBJDIR):
	$(MKDIR_P) $(OBJDIR)

clean:
		$(RMR) $(OBJDIR)

fclean: clean
		$(RMR) $(BINDIR)

re: fclean all

.PHONY: all clean fclean re
