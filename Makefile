# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 05:45:20 by tatahere          #+#    #+#              #
#    Updated: 2024/08/17 11:48:29 by tatahere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
AR	= ar rcs
RF	= rm -rf
CC	= cc

CFLAGS = -Wall -Wextra -Werror -I$(HDRDIR) -I$(LIBFTDIR) -g

NAME		=	push_swap

HDRDIR		= 	headers/
SRCDIR		= 	src/
BINDIR		= 	bin/

LIBFTDIR	=	libft/
LIBFTNAME	=	libft.a
LIBFT		=	$(LIBFTDIR)$(LIBFTNAME)

SRC			:=	shorter/ps_checker.c				\
				shorter/ps_short_small_stack.c		\
				shorter/ps_short_big_stack.c		\
				shorter/ps_short_big_stack_utils.c	\
				shorter/ps_shorter.c				\
				stack/ps_stack.c					\
				stack/ps_swap.c						\
				stack/ps_push.c						\
				stack/ps_rotate.c					\
				stack/ps_rev_rotate.c				\
				stack/ps_utils.c					\
				parse/ps_parse.c					\
				parse/ps_check_errors.c				\

OBJ			:=	${SRC:.c=.o}
DEP			:=	${SRC:.c=.d}

DEP			:=	$(addprefix $(BINDIR), $(DEP))
SRC			:=	$(addprefix $(SRCDIR), $(SRC))
OBJ			:=	$(addprefix $(BINDIR), $(OBJ))

# build the library
all: $(NAME) Makefile

bonus: checker

checker: src/bonus/ps_linux_checker.c $(BINDIR) $(OBJ) $(LIBFT) Makefile
	$(CC) $(CFLAGS) $< $(OBJ) $(LIBFT) -o checker

$(NAME): src/main.c $(BINDIR) $(OBJ) $(LIBFT) Makefile
	$(CC) $(CFLAGS) $< $(OBJ) $(LIBFT) -o $(NAME)

$(BINDIR)%.o: $(SRCDIR)%.c Makefile
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(BINDIR):
	mkdir $(BINDIR)
	mkdir $(BINDIR)/parse
	mkdir $(BINDIR)/stack
	mkdir $(BINDIR)/shorter

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	rm -rf bin
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -rf $(NAME) checker
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus test

-include $(DEP)
