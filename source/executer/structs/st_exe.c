/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:45:53 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/16 23:05:23 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void st_exe_clear(t_exe *exe)
{
	close(exe->fds[0]);
	close(exe->fds[1]);
	close(exe->pipe_base[0]);
	close(exe->pipe_base[1]);
	close(exe->pipe_here[0]);
	close(exe->pipe_here[1]);
	close(exe->fd_i);
	close(exe->fd_o);
}

void st_exe_init(t_exe *exe)
{
	exe->fds[0] = dup(STDIN_FILENO);
	exe->fds[1] = dup(STDOUT_FILENO);
	exe->pipe_base[0] = -1;
	exe->pipe_base[1] = -1;
	exe->pipe_here[0] = -1;
	exe->pipe_here[1] = -1;
	exe->fd_i = -1;
	exe->fd_o = -1;
}
