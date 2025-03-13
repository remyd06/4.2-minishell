/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:48:25 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/13 13:14:13 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    exit_func(t_ms *ms, t_env *env)
{
    printf("exit\n");
    free_tok(ms);
    // free_envarray(ms);
    free_env(env);
    exit(0);
}