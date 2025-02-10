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

//ENV chained list.
typedef	struct s_env
{
	char			*name;
	char			*arg;
	struct s_env	*next;
}	t_env;

//Lexer struct.
typedef struct	s_lexer
{
	int			nb_of_tokens;
	int			*tokens;
	char		**tokens_array;
}	t_lexer;

//Parser struct.
typedef struct	s_parser
{
	int			nb_pipe;
}	t_parser;

//Main struct.
typedef struct	s_ms 
{
	t_lexer		lexer;
	t_parser	parser;
	char		*input;
	char		**env_array;
}	t_ms;

/******************************************************************************
 *                                 L E X E R                                  *
******************************************************************************/
//Count the nb of tokens in the input.
int		count_token(t_ms *ms);
//Split and categorize each element of the input in a **array with his token.
void	tokenizer(t_ms *ms);
//Count the nb of pipe in the input.
void	count_pipe(t_ms *ms);

/******************************************************************************
 *                                P A R S E R                                  *
******************************************************************************/
//Main file for the parsing.
t_bool	parser(t_ms *ms, t_env *env);
//Parse and convert all tokens between "" or '' in a WORD token (except $) for "".
t_bool	handle_quote(t_ms *ms, t_env *env);
//Check if a PIPE is surronded by WORDS.
t_bool	handle_pipes(t_ms *ms);
//Check if REDIR is followed by WORD.
t_bool	handle_redir(t_ms *ms);
//Join in one token all the string between "" or ''.
void	union_quote(t_ms *ms);
//Free the old output and write the new one without NA tokens or WSPACE tokens.
void	final_sort(t_ms *ms);
//Union all words who are not separated by a WSPACE or NA token.
void	union_words(t_ms *ms);

/******************************************************************************
 *                              E X P A N D E R                               *
******************************************************************************/
//Initialize environement in a chained list.
void	init_env(t_ms *ms, t_env **env);
//Expander module discociated for handle expander in handle_quote function.
void	expand_var(t_ms *ms, t_env *env, int i);
//Main core of the expander for all the input string.
void	expander(t_ms *ms, t_env *env);

/******************************************************************************
 *                                 U T I L S                                  *
******************************************************************************/
//Check if the accurate char is a meta char.
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
//Free the int* tokens, and the char** token_array.
void	free_tok(t_ms *ms);
//Free the **env_array, copy of **envp.
void	free_envarray(t_ms *ms);
//Free the chained list who contained all the ENV values.
void	free_env(t_env *env);
//Handle error messages.
t_bool	ft_error(char *str);
//Create a new chained list.
t_env	*ft_lstnew(char *name, char *arg);
//Count and return the nb of char up to the specified char.
int		ft_strnlen(char *str, char c);
//Count and return the nb of char form the specified char to the end.
int		ft_strllen(char *str, char c);
//Copy the the string up to the specified char. Only for expander function.
char	*ft_strncpy_exp(char *str, char c);
//Copy the the string from the specified char to the end. Only for expander function.
char	*ft_strlcpy_exp(char *src, char c);
//Count and return the nb of character in a string.
int		ft_strlen(char *str);
//Duplicate with malloc a string.
char	*ft_strdup(char *str);
//Copy the src string in the dest string.
char	*ft_strcpy(char *src, char *dest);
//Compare two strings and return TRUE if they are the same, or FALSE if not.
t_bool	ft_strcmp(char *str1, char *str2);
//Count the nb of char* un a char**.
int		ft_lenarray(char **array);
//Handle Ctrl + C.
void	handle_macro(int sig);
//Handle Ctrl + \\.
void	handle_sigquit(int sig);
//Add at the end of src, add.
void    ft_strcat(char *src, char *add);

//Main file.
int		main(int __attribute__((unused)) argc, char __attribute((unused)) **argv, char **envp);


#endif
