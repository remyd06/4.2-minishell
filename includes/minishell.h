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

# define MAX_OUTPUT_LENGHT 1024
# define ENV 				__environ

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
	DOLLAR,				// $
	NA,					// NULL token
	END,				// End of the array
}	t_token;

typedef struct	s_lexer
{
	int			nb_of_tokens;
	int			*tokens;
	char		**tokens_array;
}	t_lexer;

typedef struct	s_parser
{
	int			nb_pipe;
}	t_parser;

typedef struct	s_expand
{
	char	*buffer_name;
	char	*buffer_arg;
}	t_expand;

typedef	struct s_env
{
	char			*name;
	char			*arg;
	struct s_env	*next;
}	t_env;

typedef struct	s_ms 
{
	t_lexer		lexer;
	t_parser	parser;
	t_expand	expand;
	char		*input;
	char		*buffer;
}	t_ms;



/******************************************************************************
 *                                 L E X E R                                  *
******************************************************************************/

//Count the nb of tokens in the input.
int		count_token(t_ms *ms);
//Split and categorize each element of the input in a **array with his token.
void	tokenizer(t_ms *ms);

void	count_pipe(t_ms *ms);

/******************************************************************************
 *                                P A R S E R                                  *
******************************************************************************/
//
void	parser(t_ms *ms);
//
t_bool	handle_quote(t_ms *ms);
//
t_bool	handle_pipes(t_ms *ms);

/******************************************************************************
 *                              E X P A N D E R                               *
******************************************************************************/
//
void	init_env(t_ms *ms, t_env **env);

/******************************************************************************
 *                                 U T I L S                                  *
******************************************************************************/

//Check if the accurate char is a meta char.t_env	*ft_lstnew(char *name, char *arg)
t_bool	ft_ismeta(char c);
//Check if the accurate char is a printable char.
t_bool	ft_isprint(int c);
//Check if the accurate char is a space char.
t_bool	ft_isspace(char c);
//Copy the *src in the *dest of x size.
char	*ft_strncpy(char *src, char *dest, int size);
//The MINISHELL menu printer.
void	main_interface_print(void);
//The temp file for test all the values.
void	print_tester_value(t_ms *ms);
//
void	free_all(t_ms *ms);
//
t_bool	ft_error(char *str);
//
t_env	*ft_lstnew(char *name, char *arg);
//
int		ft_strnlen(char *str, char c);
//
char	*ft_strlcpy_exp(char *src, char c);
//
int		ft_strllen(char *str, char c);
//
int		ft_strlen(char *str);
//
char	*ft_strncpy_exp(char *str, char c);

//Main file.
int		main(void);


#endif
