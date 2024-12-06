/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:32:56 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/06 15:21:28 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_ms *ms, char *buffer)
{
	int	i;

	if (buffer)
		free(buffer);
	i = 0;
	while (ms->lexer.tokens_array && ms->lexer.tokens_array[i])
		free(ms->lexer.tokens_array[i++]);
	free(ms->lexer.tokens_array);
	free(ms->lexer.tokens);
	ms->lexer.tokens_array = NULL;
	ms->lexer.tokens = NULL;
}

void	init_shell(t_ms *ms)
{
	ms->lexer.nb_of_tokens = 0;
	ms->lexer.tokens_array = NULL;
	ms->lexer.tokens = NULL;
}

int	main(void)
{
	t_ms	ms;
	char	*buffer;

	main_interface_print();
	while (1)
	{
		init_shell(&ms);
		buffer = readline(YEL"MINISHELL> "ENDCL);
			if (!buffer)
				return (0);
		ms.input = buffer;
		if (buffer)
			add_history(buffer);
		tokenizer(&ms);
		print_tester_value(&ms);
		free_all(&ms, buffer);
	}
}
