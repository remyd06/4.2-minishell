/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:40:57 by rdedola           #+#    #+#             */
/*   Updated: 2025/02/10 20:40:57 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool  is_n(t_ms *ms)
{
    t_bool  n;

    n = TRUE;
    if (ft_strcmp(ms->lexer.tokens_array[1], "-n"))
        n = FALSE;
    return (n);
}

void    echo_func(t_ms *ms)
{
    t_bool  n;
    int     i;

    n = is_n(ms);
    if (!n)
    {
        i = 2;
        while (i < ms->lexer.nb_of_tokens && ms->lexer.tokens[i] == WORD)
        {
            printf("%s", ms->lexer.tokens_array[i++]);
            if (ms->lexer.tokens[i] == WORD)
                printf(" ");
        }
    }
    else
    {
        i = 1;
        while (i < ms->lexer.nb_of_tokens && ms->lexer.tokens[i] == WORD)
        {
            printf("%s", ms->lexer.tokens_array[i++]);
            if (ms->lexer.tokens[i] == WORD)
                printf(" ");
        }
        printf("\n");
    }
}
