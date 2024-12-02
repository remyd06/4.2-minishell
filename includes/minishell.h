/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:33:10 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/02 20:48:27 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

// Fonctions liées à la bibliothèque readline (libreadline)
#include <stdio.h>              // printf, perror
#include <stdlib.h>             // malloc, free, exit, getenv
#include <unistd.h>             // write, access, read, close, fork, pipe, 
                          		// dup, dup2, getcwd, chdir, isatty, ttyname, ttyslot
#include <fcntl.h>              // open, unlink
#include <string.h>             // strerror
#include <signal.h>             // signal, sigaction, sigemptyset, sigaddset, kill
#include <sys/stat.h>           // stat, lstat, fstat
#include <dirent.h>             // opendir, readdir, closedir

# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YEL		"\033[33m"
# define ENDCL		"\033[0m"

# define MAX_OUTPUT_LENGHT = 1024

typedef enum	e_bool
{
	TRUE = 1,
	FALSE = 0
	
}	t_bool;

typedef struct	s_ms 
{
	char	**output_array;
	
}	t_ms;


/* UTILS */

//The MINISHELL menu printer.
void	main_interface_print(void);
int		main(void);



#endif
