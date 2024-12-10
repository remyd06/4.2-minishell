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

void	free_all(t_ms *ms)
{
	int	i;

	if (ms->buffer)
		free(ms->buffer);
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
	ms->parser.already_free = FALSE;
	ms->parser.is_pipe = FALSE;
}

int	main(void)
{
	t_ms	ms;

	main_interface_print();
	while (1)
	{
		init_shell(&ms);
		ms.buffer = readline(YEL"MINISHELL> "ENDCL);
			if (!ms.buffer)
				return (0);
		ms.input = ms.buffer;
		if (ms.buffer)
			add_history(ms.buffer);
		tokenizer(&ms);
		parser(&ms);
		print_tester_value(&ms);
		if (ms.parser.already_free != TRUE)
			free_all(&ms);
	}
}
