# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 17:33:57 by rdedola           #+#    #+#              #
#    Updated: 2024/12/06 15:22:10 by rdedola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE			=	minishell

# Files
VPATH 		=	source \
				source/parsing/lexer \
				source/parsing/parser \
				source/parsing/expander \
				source/execution/builtins \
				source/utils \

SRC			=	main.c \

# Parsing
LEXER		=	count_token.c \
				tokenizer.c \

PARSER		=	parser.c \
				count_pipe.c \
				handle_quotes.c \
				handle_pipes.c \
				handle_redir.c \
				union_quote.c \
				union_words.c \
				final_sort.c \

EXPANDER	=	init_env.c \
				expand_var.c \
				expander.c \

# Execution
BUILTINS	=	builtins_supervisor.c \
				env_func.c \
				pwd_func.c \
				echo_func.c \
				exit_func.c \

# Utils
SRC_UTILS	=	main_interface_print.c \
				print_tester_value.c \
				sigmacros.c \
				ft_error.c \
				ft_ismeta.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_strncpy.c \
				ft_strncpy_exp.c \
				ft_strlcpy_exp.c \
				ft_lstnew.c \
				ft_strnlen.c \
				ft_strllen.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_freebox.c \
				ft_lenarray.c \
				ft_strcat.c \
				ft_isredir.c \
				ft_strchr.c \
				ft_ismetatoken.c \
				
SOURCES		=	${SRC} ${SRC_UTILS} ${LEXER} ${PARSER} ${EXPANDER} ${BUILTINS}
OBJECTS		=	${SOURCES:%.c=obj/%.o}

# Variables
CC			=	cc
CFLAGS		=	-Iincludes -Wall -Wextra -fsanitize=address -g
RM			=	rm -rf

# Colors
DEF_COLOR	= \033[0;39m
COLOR		= \033[1;32m

# Makefile
all:		${EXE}

${EXE}:		${OBJECTS}
			@${CC} ${CFLAGS} ${OBJECTS} -lreadline -o ${EXE}
			@${CC} ${CFLAGS} ${OBJECTS} -lreadline -o ${EXE}
			@echo "${COLOR}╔══════════════════════════╗${DEF_COLOR}"
			@echo "${COLOR}║    Minishell compiled    ║${DEF_COLOR}"
			@echo "${COLOR}╚══════════════════════════╝${DEF_COLOR}"

obj/%.o:	%.c
			@mkdir -p obj/$(dir $<)
			@${CC} ${CFLAGS} -c $< -o $@

clean:
			@${RM} obj
			@${RM} #{EXE}.log
			@echo "${COLOR}╔══════════════════════════╗${DEF_COLOR}"
			@echo "${COLOR}║    Minishell cleaned!    ║${DEF_COLOR}"
			@echo "${COLOR}╚══════════════════════════╝${DEF_COLOR}"

fclean:		clean
			@${RM} ${EXE}

re:			fclean all

.PHONY:		all clean fclean re
