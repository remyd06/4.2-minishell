/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:57:20 by rdedola           #+#    #+#             */
/*   Updated: 2025/02/10 14:57:20 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     count_len(t_ms *ms, int i)
{
    int len = 0;

    while (i < ms->lexer.nb_of_tokens && ms->lexer.tokens[i] != END
           && ms->lexer.tokens[i] != WSPACE)
    {
        if (ms->lexer.tokens[i] != NA)
            len += ft_strlen(ms->lexer.tokens_array[i]);
        i++;
    }
    return len;
}

void    split_func(t_ms *ms, char *tmp, int i)
{
    free(ms->lexer.tokens_array[i]);
    ms->lexer.tokens_array[i++] = ft_strdup(tmp);
}

void union_words(t_ms *ms)
{
    char    *tmp;
    int     i;

    i = 0;
    while (i < ms->lexer.nb_of_tokens)
    {
        if (ms->lexer.tokens[i] != NA && ms->lexer.tokens[i] != WSPACE)
        {
            tmp = malloc(sizeof(char) * (count_len(ms, i) + 1));
            tmp[0] = '\0';
            while (i < ms->lexer.nb_of_tokens && ms->lexer.tokens[i] != END
                && ms->lexer.tokens[i] != WSPACE)
            {
                if (ms->lexer.tokens[i] != NA)
                    ft_strcat(tmp, ms->lexer.tokens_array[i]);
                if (ms->lexer.tokens[i + 1] == WSPACE || ms->lexer.tokens[i + 1] == END)
                    split_func(ms, tmp, i);
                else
                    ms->lexer.tokens[i] = NA;
                i++;
            }
            free(tmp);
        }
        i++;
    }
}
