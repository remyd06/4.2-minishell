/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:20:09 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/07 22:28:57 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_ms *ms, t_env *env)
{
	count_pipe(ms);
	if (!handle_quote(ms, env))
		return ;
	if (!handle_pipes(ms))
		return ;
	if (!handle_redir(ms))
		return ;
	//union_quote(ms);
}
