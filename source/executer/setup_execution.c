/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:26:23 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/17 17:36:23 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_loop(t_ms *ms, t_exe *exe, size_t index);
static void run_execution(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index);
static void execute_builtins(t_ms *ms, t_exe *exe, t_cmd *cmd);
static void execute_binaries(t_ms *ms, t_exe *exe, t_cmd *cmd);

static void debug(t_cmd *cmd);//temporaire

void	execute(t_ms *ms)
{
	t_exe	exe;

	preparse(ms);
	st_exe_init(&exe);
	execute_loop(ms, &exe, 0);
	st_exe_clear(&exe);
}

static void	execute_loop(t_ms *ms, t_exe *exe, size_t index)
{
	t_cmd	cmd;

	st_cmd_init(&cmd);
	if (index > 0 && ms->lexer.tokens[index - 1] == PIPE)
		cmd.has_pipe_i = true;
	while (index == 0 || ms->lexer.tokens[index - 1] != END)
	{
		reparse(ms, exe, &cmd, index);
		if (cmd.is_finished == true)
			return (run_execution(ms, exe, &cmd, index), st_cmd_clear(&cmd));
		++index;
	}
}

static void run_execution(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index)
{
	debug(cmd);

	if (cmd->has_file_i == true)
		exe->fd_i = open(cmd->rfi, O_RDONLY, 0644);

	pipe(exe->pipe_base);
	if (cmd->has_heredoc == true)
		pipe(exe->pipe_here);

	ft_basename(cmd->cmd, cmd->nme);
	if (ft_strnstr("cd;echo;env;exit;export;pwd;unset", cmd->nme, 33) != NULL)
		execute_builtins(ms, exe, cmd);
	else
		execute_binaries(ms, exe, cmd);

	pipeline_close(exe, cmd);

	execute_loop(ms, exe, index + 1);
	waitpid(cmd->pid, NULL, 0);
}

static void execute_builtins(t_ms *ms, t_exe *exe, t_cmd *cmd)
{
	pipeline_open(exe, cmd);
	g_exit_status = exe_builtin(cmd, ms);
	dup2(exe->fds[0], STDIN_FILENO);
	dup2(exe->fds[1], STDOUT_FILENO);
}

static void execute_binaries(t_ms *ms, t_exe *exe, t_cmd *cmd)
{
	char	arg[BUFSIZ];
	char	**earg;
	t_list	*larg;

	ft_bzero(arg, BUFSIZ);
	ft_strlcat(arg, cmd->cmd, BUFSIZ);
	ft_strlcat(arg, " ", BUFSIZ);
	if (cmd->has_option == true)
	{
		ft_strlcat(arg, "-", BUFSIZ);
		ft_strlcat(arg, cmd->opt, BUFSIZ);
	}
	larg = cmd->arg;
	while (larg)
	{
		ft_strlcat(arg, " ", BUFSIZ);
		ft_strlcat(arg, larg->content, BUFSIZ);
		larg = larg->next;
	}

	earg = ft_split(arg, ' ');
	get_path(cmd, ms);
	if (ft_fork(&cmd->pid) == 0)
	{
		pipeline_open(exe, cmd);
		ft_close(&exe->pipe_base[0]);
		ft_close(&exe->pipe_base[1]);

		if (access(cmd->path, F_OK) != 0)
			ft_perror(NULL, cmd->cmd, NULL, "commande introuvable");
		else
		{
			execve(cmd->path, earg, ft_env_to_array(ms->env));
			if (access(cmd->path, X_OK) != 0)
			{
				ft_perror("minishell", cmd->cmd, NULL, strerror(errno));
				exit(126);
			}
		}
		exit(127);
	}
	ft_free_deep(earg);
}
// fonction debug, temporaire !
static void debug(t_cmd *cmd)
{
	printf("Cmd: ] %s [\n", cmd->cmd);
	printf("Arg: ");
	t_list *larg = cmd->arg;
	while (larg)
	{
		printf("] %s [", (char *) larg->content);
		larg = larg->next;
	}
	printf("\n");
	printf("Opt: ] %s [\n", cmd->opt);
	printf("Rio: file_i: %i; file_o: %i; pipe_i: %i; pipe_o: %i; doc: %i\n", cmd->has_file_i, cmd->has_file_o, cmd->has_pipe_i, cmd->has_pipe_o, cmd->has_heredoc);
	printf("Doc: ] %s [\n", cmd->doc);
}
