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

# include "libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

# define RED		"\001\033[31;1m\002"
# define GREEN		"\001\033[32;1m\002"
# define YEL		"\001\033[33;1m\002"
# define PURP		"\001\033[35;1m\002"
# define ENDCL		"\001\033[0m\002"

# define MAX_OUTPUT_LENGHT 1024

extern int	g_exit_status;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef enum e_token
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
typedef struct s_env
{
	char			*name;
	char			*arg;
	t_bool			is_egal;
	struct s_env	*next;
}	t_env;

//Lexer struct.
typedef struct s_lexer
{
	int			nb_of_tokens;
	int			*tokens;
	char		**tokens_array;
}	t_lexer;

//Parser struct.
typedef struct s_parser
{
	int			nb_pipe;
}	t_parser;

//Main struct.
typedef struct s_ms
{
	t_env		*env;
	t_lexer		lexer;
	t_parser	parser;
	char		*input;
	char		**env_array;
	t_bool		is_env;
	bool		is_error;
	bool		is_exit;
}	t_ms;

//Pipe struct.
typedef struct s_exe {
	int			fds[2];
	int			pipe_base[2];
	int			pipe_here[2];
	int			fd_i;
	int			fd_o;
}	t_exe;

//Execut struct.
typedef struct s_cmd {
	pid_t		pid;
	t_list		*arg;              // argument
	char		cmd[BUFSIZ];       // commande
	char		nme[BUFSIZ];       // name          (base name)
	char		rfi[BUFSIZ];       // file entrer   (redir file in)
	char		rfo[BUFSIZ];       // file sortie   (redir file out)
	char		doc[BUFSIZ];       // heredoc
	char		opt[BUFSIZ];       // heredoc
	char		path[BUFSIZ];      // PATH
	bool		has_file_i;        // si redirection d'entre
	bool		has_file_o;        // si redirection de sortie
	bool		has_pipe_i;        // si pipe d'entre
	bool		has_pipe_o;        // si pipe de sortie
	bool		has_option;        // si flags
	bool		has_heredoc;       // si heredoc
	bool		is_finished;       // si finis
	size_t		count;
}	t_cmd;


/******************************************************************************
 *                                   E N V                                    *
******************************************************************************/

char	**set_default_env(t_ms *ms, char **envp);
void	init_env(t_ms *ms, t_env **env);
void	setenv_array(t_ms *ms, char **envp);

/******************************************************************************
 *                                 L E X E R                                  *
******************************************************************************/

//Count the nb of tokens in the input.
int		count_token(t_ms *ms);
//Split and categorize each element of the input in a **array with his token.
void	tokenizer(t_ms *ms, int x, int y);
//Count the nb of pipe in the input.
void	count_pipe(t_ms *ms);

/*******************************************************************************
 *                                P A R S E R                                  *
*******************************************************************************/

//Main file for the parsing.
t_bool	parser(t_ms *ms, t_env *env);
//Parse and convert all tokens in "" or '' in a WORD token (except $) in "".
t_bool	handle_quote(t_ms *ms, t_env *env, int singleq, int doubleq);
//Check if a PIPE is surronded by WORDS.
t_bool	handle_pipes(t_ms *ms);
//Check if REDIR is followed by WORD.
t_bool	handle_redir(t_ms *ms);
//Join in one token all the string between "" or ''.
void	union_quote(t_ms *ms, int i, int j);
//Free the old output and write the new one without NA tokens or WSPACE tokens.
void	final_sort(t_ms *ms);
//Union all words who are not separated by a WSPACE or NA token.
void	union_words(t_ms *ms, int i);

/******************************************************************************
 *                              E X P A N D E R                               *
******************************************************************************/

//Expander module discociated for handle expander in handle_quote function.
void	expand_var(t_ms *ms, t_env *env, int i);
//Expander module for the $? var.
void	expand_retvar(t_ms *ms, int i);
//Search the var in the env chained list.
char	*search_var(char *str, t_env *env);
//Main core of the expander for all the input string.
void	expander(t_ms *ms, t_env *env);
//It modifies or adds an environment variable.
void	modify_var(char *name, char *new, bool egal, t_env *env);

/******************************************************************************
 *                              B U I L T I N S                               *
******************************************************************************/

int		exe_builtin(t_cmd *cmd, t_ms *ms);
int		builtin_echo(t_cmd *cmd);
int		builtin_pwd(t_ms *ms);
int		builtin_cd(t_cmd *cmd, t_ms *ms);
int		builtin_unset(t_cmd *cmd, t_ms *ms);
int		builtin_export(t_cmd *cmd, t_ms *ms);
int		builtin_exit(t_cmd *cmd, t_ms *ms);
int		builtin_env(t_env *env);

/******************************************************************************
 *                             E X E C U T I O N                              *
******************************************************************************/

void	execute(t_ms *ms);
void	st_cmd_clear(t_cmd *cmd);
void	st_cmd_init(t_cmd *cmd);
void	st_exe_clear(t_exe *exe);
void	st_exe_init(t_exe *exe);
void	pipeline_open(t_exe *exe, t_cmd *cmd);
void	pipeline_close(t_exe *exe, t_cmd *cmd);
void	preparse(t_ms *ms);
void	reparse(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index);
void	rep_rfo(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index);
void	rep_doc(t_ms *ms, t_cmd *cmd, size_t index);
void	rep_end(t_ms *ms, t_cmd *cmd, size_t index);
void	rep_arg(t_ms *ms, t_cmd *cmd, size_t index);
void	rep_cmd(t_ms *ms, t_cmd *cmd, size_t index);
void	rep_opt(t_ms *ms, t_cmd *cmd, size_t index);
void	rep_rfi(t_ms *ms, t_cmd *cmd, size_t index);
bool 	rep_is_rfo(t_ms *ms, t_cmd *cmd, size_t index);
bool	rep_is_doc(t_ms *ms, t_cmd *cmd, size_t index);
bool	rep_is_end(t_ms *ms, t_cmd *cmd, size_t index);
bool	rep_is_arg(t_ms *ms, t_cmd *cmd, size_t index);
bool	rep_is_cmd(t_ms *ms, t_cmd *cmd, size_t index);
bool	rep_is_opt(t_ms *ms, t_cmd *cmd, size_t index);
bool	rep_is_rfi(t_ms *ms, t_cmd *cmd, size_t index);
void	get_path(t_cmd *cmd, t_ms *ms);
pid_t	ft_fork(int *pid);
int		ft_close(int *fd);

/******************************************************************************
 *                                 U T I L S                                  *
******************************************************************************/

//Check if the accurate char is a meta char.
t_bool	ft_ismeta(char c);
//Check if the accurate char is a printable char.
t_bool	ft_risprint(int c);
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
void	free_envarray(t_ms *ms, char **envp);
//Free the chained list who contained all the ENV values.
void	free_env(t_env *env);
//Handle error messages.
t_bool	ft_error(char *str);
//Create a new chained list.
t_env	*ft_rlstnew(char *name, char *arg);
//Count and return the nb of char up to the specified char.
int		ft_strnlen(char *str, char c);
//Count and return the nb of char form the specified char to the end.
int		ft_strllen(char *str, char c);
//Copy the the string up to the specified char. Only for expander function.
char	*ft_strncpy_exp(char *str, char c);
//Copy the the string from the specified char to the end. Only for expander.
char	*ft_strlcpy_exp(char *src, char c);
//Count and return the nb of character in a string.
int		ft_rstrlen(char *str);
//Duplicate with malloc a string.
char	*ft_rstrdup(char *str);
//Copy the src string in the dest string.
char	*ft_strcpy(const char *src, char *dest);
//Compare two strings and return TRUE if they are the same, or FALSE if not.
t_bool	ft_strcmp(char *str1, char *str2);
//Count the nb of char* un a char**.
int		ft_lenarray(char **array);
//Handle Ctrl + C.
void	handle_macro(int sig);
//Handle Ctrl + \\.
void	handle_sigquit(int sig);
//Verify if the token is a REDIR or not.
t_bool	ft_isredir(t_ms *ms, int i);
//Search c in *str and return TRUE if c is found.
t_bool	ft_rstrchr(char *str, char c);


// AUTRE :

t_bool	ft_ismeatoken(t_ms *ms, int i);
char	*ft_rstrjoin(char *src, char *add);
char	*ft_ritoa(int n);
char	**ft_env_to_array(t_env *list);
void	ft_lstdelone_mod(t_env *lst, void (*del)(void*));
int		ft_lstsize_env(t_env *lst);
void	ft_basename(const char *path, char *result);
void	ft_write(int fd, const char *str);
void	ft_perror(const char *shell, char const *cmd, char const *arg,
	char const *msg);


//Main file.
int		main(int __attribute__((unused)) argc,
			char __attribute((unused)) **argv, char **envp);

#endif
