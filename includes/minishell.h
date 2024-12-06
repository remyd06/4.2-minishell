/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:33:10 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/06 15:22:07 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>    		// opendir, readdir, closedir
# include <fcntl.h>     		// open
# include <signal.h>    		// signal, sigaction, sigemptyset, sigaddset, kill
# include <stdio.h>     		// printf, perror
# include <stdlib.h>    		// malloc, free, exit, getenv
# include <string.h>    		// strerror
# include <sys/ioctl.h> 		// ioctl
# include <sys/stat.h>  		// stat, lstat, fstat
# include <sys/wait.h>  		// wait, waitpid, wait3, wait4
# include <term.h>      		// tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <termios.h>   		// tcsetattr, tcgetattr
# include <unistd.h>    		// write, access, read, close, fork
								// getcwd, chdir, unlink, execve, dup
								// dup2, pipe, isatty, ttyname, ttyslot
# include <readline/readline.h> // readline, rl_clear_history, rl_on_new_line
# include <readline/history.h>  // add_history
# include <stdbool.h>           // Booleans
								// rl_replace_line, rl_redisplay

# define RED		"\033[31;1m"
# define GREEN		"\033[32;1m"
# define YEL		"\001\033[33;1m"
# define PURP		"\001\033[35;1m"
# define ENDCL		"\002\033[0m"

# define MAX_OUTPUT_LENGHT = 1024

typedef enum	e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef enum	e_token
{
	WSPACE,				// Whitespace
	WORD,				// Others
	SINGLE_QUOTE,		// '
	DOUBLE_QUOTE,		// "
	PIPE,				// |
	REDIN,				// <
	REDOUT,				// >
	HEREDOC,			// <<
	APPEND_REDIR,		// >>
	DOLLAR,				//$
}	t_token;

typedef struct	s_lexer
{
	int			nb_of_tokens;
	int			*tokens;
	char		**tokens_array;
}	t_lexer;

typedef struct	s_ms 
{
	t_lexer		lexer;
	char		*input;
	char		**output_array;
	
}	t_ms;


/* UTILS */

//The MINISHELL menu printer.
void	main_interface_print(void);
int		main(void);
int		count_token(t_ms *ms);
t_bool	ft_isspace(char c);
t_bool	ft_ismeta(char c);
t_bool	ft_isprint(int c);
void	print_tester_value(t_ms *ms);
void	tokenizer(t_ms *ms);
char	*ft_strncpy(char *src, char *dest, int size);



#endif
