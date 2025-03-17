# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 21:45:42 by jimmy             #+#    #+#              #
#    Updated: 2024/12/19 16:04:34 by nippolit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	    = 	minishell

NAME_H		=	minishell.h

INCLUDE	    =	-I./includes -I./libraries/libft

CC	 	    = 	clang
CFLAGS	    =  -Wall -Wextra -Werror -g -O3 -fsanitize=undefined,address
CCF		    =	${CC} ${CFLAGS}

LIBFT	=	./libraries/libft
LIBS	=	$(LIBFT)/libft.a
SRCS 	=	$(wildcard source/*/*.c source/*/*/*.c source/*.c *.c)
OBJS    =	${SRCS:.c=.o}

all 	: ${NAME}

${NAME} : ${OBJS}
		@make -C ${LIBFT} --no-print-directory
		@${CCF} -lreadline ${OBJS} -o ${NAME} ${LIBS}
		@printf "$(MSG_BCOLOR_SUCCESS)compiled !$(TERM_CONTROL_RESET)\n"

%.o : %.c
		@${CCF} ${INCLUDE} -c $< -o $@
		@printf "$(MSG_BCOLOR_WARNING)compilation: $< !$(TERM_CONTROL_RESET)\n"

clean  :
		@rm -rf ${OBJS}
		@make -C ${LIBFT} clean --no-print-directory
		@printf "$(MSG_BCOLOR_FAILURE)clean: $(NAME) ! $(TERM_CONTROL_RESET)\n"

fclean : clean
		@rm -rf ${NAME}
		@make -C ${LIBFT} fclean --no-print-directory

re     : fclean all

.PHONY : all, clean, fclean, re








# >>>>>>>>>> MESSAGES COLORS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

 MSG_BCOLOR_FAILURE		:=	\001\e[1;31m\002 # Rouge gras
 MSG_BCOLOR_LOGGING		:=	\001\e[1;37m\002 # Blanc gras
 MSG_BCOLOR_SUCCESS		:=	\001\e[1;32m\002 # Vert  gras
 MSG_BCOLOR_WARNING		:=	\001\e[1;33m\002 # Jaune gras


# >>>>>>>>>> TERMINAL <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

 TERM_CONTROL_CLEAR		:=	\001\e[1;1H\e[2J\002
 TERM_CONTROL_RESET		:=	\001\e[0m\002

# >>>>>>>>>> Autre <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

# ${NAME} : ${OBJS}

# ${CCF} -o ${NAME} ${OBJS}
#            ou
# ar -rsc ${NAME} ${OBJS} $(MLX_FLAGS)

# >>>>>>>>>> FIN <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
