/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:54:55 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/17 17:04:23 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int export_arg(t_env *env, char *args);
static int export_noarg(t_env *env);
static int comp_char(void *a, void *b);

int	builtin_export(t_cmd *cmd, t_ms *ms)
{
	t_list	*temp;
	int		exit_code;
	int		status_code;

	exit_code = 0;
	status_code = 0;

	if (ft_lstsize(cmd->arg) == 0)
		export_noarg(ms->env);
	else
	{
		temp = cmd->arg;
		while (temp)
		{
			status_code = export_arg(ms->env, temp->content);
			if (status_code != 0)
				exit_code = status_code;
			temp = temp->next;
		}
	}
	return (exit_code);
}

static int export_arg(t_env *env, char *arg)
{
	char	name[64];
	char	value[4096];
	bool	egal;
	int		i;

	i = 0;
	if (ft_strchr("!@#$%^&*()-+={}[]|\\:;'\"<>,?/ 0123456789", arg[i]) != NULL)
	{
		ft_perror("minishell", "export", arg, "identifiant non valable");
		return (1);
	}
	while (arg[i] != '\0' && arg[i] != '=')
	{
		if (ft_strchr("!@#$%^&*()-+={}[]|\\:;'\"<>,?/ ", arg[i]) != NULL)
		{
			ft_perror("minishell", "export", arg, "identifiant non valable");
			return (1);
		}
		++i;
	}
	i = 0;
	egal = false;
	ft_bzero(name, 64);
	ft_bzero(value, 4096);
	while (arg[i] != '\0' && arg[i] != '=')
	{
		name[i] = arg[i];
		++i;
	}
	if (arg[i] == '=')
	{
		ft_strlcpy(value, &arg[i + 1], 4096);
		egal = true;
	}
	modify_var(name, value, egal, env);
	return (0);
}

static int export_noarg(t_env *env)
{
	char	**tabenv;
	int		i;
	int		j;

	i = 0;
	tabenv = ft_env_to_array(env);
	ft_qsort((void **) tabenv, comp_char, -1);
	while (tabenv[i])
	{
		j = 0;
		ft_write(STDOUT_FILENO, "declare -x ");
		while (tabenv[i][j] != '\0' && tabenv[i][j] != '=')
			ft_write(STDOUT_FILENO, &tabenv[i][j++]);
		if (tabenv[i][j++] == '=')
		{
			ft_write(STDOUT_FILENO, "=\"");
			ft_write(STDOUT_FILENO, &tabenv[i][j]);
			ft_write(STDOUT_FILENO, "\"");
		}
		ft_write(STDOUT_FILENO, "\n");
		++i;
	}
	ft_free_deep(tabenv);
	return (1);
}

static int comp_char(void *a, void *b)
{
	unsigned char    *str1;
    unsigned char    *str2;

    str1 = (unsigned char*) a;
    str2 = (unsigned char*) b;
    while (str1++ && str2 &&(str1 - 1) == str2)
        str2++;
    return (*((unsigned char *) str1 - 1) - *(unsigned char *) str2);
}

