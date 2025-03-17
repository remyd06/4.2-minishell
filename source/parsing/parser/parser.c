/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:20:09 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/15 00:51:07 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	parser(t_ms *ms, t_env *env)
{
	count_pipe(ms);
	if (!handle_quote(ms, env, 0, 0))
	{
		g_exit_status = 2;
		return (FALSE);
	}
	if (!handle_pipes(ms))
	{
		g_exit_status = 2;
		return (FALSE);
	}
	if (!handle_redir(ms))
	{
		g_exit_status = 2;
		return (FALSE);
	}
	expander(ms, env);
	union_quote(ms, 0, 0);
	union_words(ms, 0);
	final_sort(ms);
	return (TRUE);
}
