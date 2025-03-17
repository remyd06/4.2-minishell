/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:34:24 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/17 17:03:38 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	preparse_heredoc(t_ms *ms, int index);

void	preparse(t_ms *ms)
{
	int	index;

	index = 0;
	while (ms->lexer.tokens[index] != END)
	{
		if (ms->lexer.tokens[index] == HEREDOC)
			preparse_heredoc(ms, ++index);
		++index;
	}
}

static void	preparse_heredoc(t_ms *ms, int index)
{
	char	*line;
	char	buffer[BUFSIZ];

	ft_bzero(buffer, BUFSIZ);
	while (true)
	{
		line = readline("heredoc> ");
		if (line == NULL)
		{
			ft_write(STDOUT_FILENO, "minishell: avertissement : « here-document » délimité par la fin du fichier au lieu de (« ");
			ft_write(STDOUT_FILENO, ms->lexer.tokens_array[index]);
			ft_write(STDOUT_FILENO, " »)\n");
			break ;
		}
		if (ft_strcmp(line, ms->lexer.tokens_array[index]))
		{
			ft_free(line);
			break ;
		}
		ft_strlcat(buffer, line, BUFSIZ);
		ft_strlcat(buffer, "\n", BUFSIZ);
		ft_free(line);
	}
	ft_free(ms->lexer.tokens_array[index]);
	ms->lexer.tokens_array[index] = ft_strdup(buffer);
}
