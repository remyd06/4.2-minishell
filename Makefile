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
SRC			=	main.c \

LEXER		=	source/lexer/count_token.c \
				source/lexer/tokenizer.c \

SRC_UTILS	=	source/utils/main_interface_print.c \
				source/utils/print_tester_value.c \
				source/utils/ft_ismeta.c \
				source/utils/ft_isprint.c \
				source/utils/ft_isspace.c \
				source/utils/ft_strncpy.c \
				
SOURCES		=	${SRC} ${SRC_UTILS} ${LEXER}
OBJECTS		=	${SOURCES:%.c=obj/%.o}

# Variables
CC			=	cc
CFLAGS		=	-Iincludes -Wall -Werror -Wextra
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
