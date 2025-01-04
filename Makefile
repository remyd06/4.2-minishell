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
				source/utils \

SRC			=	main.c \

LEXER		=	count_token.c \
				tokenizer.c \

PARSER		=	parser.c \
				handle_quotes.c \
				handle_pipes.c \
				handle_redir.c \
				count_pipe.c \

EXPANDER	=	init_env.c

SRC_UTILS	=	main_interface_print.c \
				print_tester_value.c \
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
				
SOURCES		=	${SRC} ${SRC_UTILS} ${LEXER} ${PARSER} ${EXPANDER}
OBJECTS		=	${SOURCES:%.c=obj/%.o}

# Variables
CC			=	cc
CFLAGS		=	-Iincludes -Wall -Wextra -fsanitize=address -g
RM			=	rm -rf

# Makefile
all:		${EXE}

${EXE}:		${OBJECTS}
			@${CC} ${CFLAGS} ${OBJECTS} -lreadline -o ${EXE}

obj/%.o:	%.c
			@mkdir -p obj/$(dir $<)
			@${CC} ${CFLAGS} -c $< -o $@

clean:
			@${RM} obj
			@${RM} #{EXE}.log

fclean:		clean
			@${RM} ${EXE}

re:			fclean all

.PHONY:		all clean fclean re
