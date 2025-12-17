NAME			= minishell
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
AR				= ar
ARFLAGS			= -rcs
RM				= rm -f

LIBFT = ./libft
LIBFT_A = ./libft/libft.a

########  SRCS  §  BSRCS ########
SRCS			=	main.c \
					readline.c \

##BSRCS			=	

OBJS			= $(SRCS:%.c=%.o)
##BOBJS			= $(BSRCS:%.c=%.o)

all : $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@make -C $(LIBFT)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

##bonus : $(BOBJS)
##	$(AR) $(ARFLAGS) $(NAME) $(BOBJS)

clean :
	$(RM) $(OBJS) $(LIBFT_A)
	@make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re 