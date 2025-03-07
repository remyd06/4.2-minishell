/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_supervisor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:01:18 by rdedola           #+#    #+#             */
/*   Updated: 2025/02/10 19:01:18 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    builtins_supervisor(t_ms *ms, t_env *env)
{
    if (ft_strcmp(ms->lexer.tokens_array[0], "env"))
        env_func(ms);
    else if (ft_strcmp(ms->lexer.tokens_array[0], "pwd"))
        pwd_func(env);
    else if (ft_strcmp(ms->lexer.tokens_array[0], "echo"))
        echo_func(ms);
    else if (ft_strcmp(ms->lexer.tokens_array[0], "exit"))
        exit_func(ms, env);
    else
        printf(RED"Command '%s' not found.\n"ENDCL, ms->lexer.tokens_array[0]);
}