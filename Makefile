NAME			= minishell
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
ADFLAGS			= -Wall -Wextra -Werror -lreadline
AR				= ar
ARFLAGS			= -rcs
RM				= rm -f

LIBFT = ./libft
LIBFT_A = ./libft/libft.a

OBJ_DIR = objects

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    READLINE_DIR	= $(shell brew --prefix readline)
    READLINE_INC	= -I$(READLINE_DIR)/include
    READLINE_LIB	= -L$(READLINE_DIR)/lib -lreadline
else
    READLINE_INC	=
    READLINE_LIB	= -lreadline
endif

########  SRCS  ########
SRCS			=	main.c \
					src/parsing/main_loop.c \
					src/parsing/help.c \
					src/parsing/lexer.c \
					src/parsing/lexing_utils.c \
					src/parsing/lexing_utils2.c \
					src/signal/signals.c \
					src/builtins/builtins.c \
					src/builtins/builtin_echo.c \
					src/builtins/builtin_pwd.c \
					src/builtins/builtin_env.c \
					src/builtins/builtin_exit.c \
					src/builtins/builtin_cd.c \
					src/builtins/builtin_export.c \
					src/builtins/builtin_unset.c \
					src/env/env_init.c \
					src/env/env_utils.c \
					test_funcs.c \

OBJS			= $(SRCS:%.c=$(OBJ_DIR)/%.o)

all : $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@make -C $(LIBFT)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(READLINE_LIB) -o $(NAME)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(READLINE_INC) -c $< -o $@

clean :
	$(RM) $(OBJS) $(LIBFT_A)
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 