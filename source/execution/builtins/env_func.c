/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:57:52 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/11 17:12:35 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void env_func(t_env *env)
{
    while (env)
    {
        if (env->is_egal)
            printf("%s=%s\n", env->name, env->arg);
        else
            printf("%s\n", env->name);
        env = env->next;
    }
}
