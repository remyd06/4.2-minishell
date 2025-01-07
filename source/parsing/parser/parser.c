/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:20:09 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/07 15:20:47 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_ms *ms, t_env *env)
{
	count_pipe(ms);
	if (!handle_quote(ms))
		return ;
	if (!handle_pipes(ms))
		return ;
	if (!handle_redir(ms))
		return ;
	expand_var(ms, env);
	//union_quote(ms);
}
