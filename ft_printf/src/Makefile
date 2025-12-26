# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elhirond <elhirond@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 15:24:38 by elhirond          #+#    #+#              #
#    Updated: 2025/10/08 19:05:14 by elhirond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       	= libftprintf.a
LIBFTDIR  	= libft
LIBFT    	= $(LIBFTDIR)/libft.a

CC        	= gcc
CFLAGS    	= -Wall -Wextra -Werror -Iinclude -I$(LIBFTDIR)
RM        	= rm -f

SRCS_LIB   	= src/ft_printf.c src/ft_parse_utils.c \
			src/ft_print_utils.c src/ft_format_utils.c src/ft_print_nbr.c \
			src/ft_print_padding.c src/ft_print_unsigned.c \
			src/ft_print_hexa.c src/ft_print_ptr.c src/ft_format_literal.c
OBJS      	= $(SRCS_LIB:src/%.c=obj/%.o)

all: 		$(LIBFT) $(NAME)

$(LIBFT):
			@make -C $(LIBFTDIR)

obj/%.o: 	src/%.c
			@mkdir -p obj
			cp $(LIBFT) $(NAME)
			$(CC) $(CFLAGS) -c $< -o $@ -g

$(NAME): 	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus: 		all

clean:
			$(RM) $(OBJS)
			@make clean -C $(LIBFTDIR)

fclean: 	clean
			$(RM) $(NAME)
			@make fclean -C $(LIBFTDIR)

re: 		fclean all

.PHONY: 	all clean fclean re run
