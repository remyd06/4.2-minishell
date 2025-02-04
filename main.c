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

void	handle_macro(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	init_shell(t_ms *ms)
{
	ms->lexer.nb_of_tokens = 0;
	ms->lexer.tokens_array = NULL;
	ms->lexer.tokens = NULL;
	ms->parser.nb_pipe = 0;
}

int	main(int __attribute__((unused)) argc, char __attribute((unused)) **argv, char **envp)
{
	t_ms	ms;
	t_env	*env;

	ms.env_array = envp;
	init_env(&ms, &env);
	main_interface_print();
	signal(SIGINT, handle_macro);
	while (1)
	{
		init_shell(&ms);
		ms.buffer = readline(YEL"MINISHELL> "ENDCL);
		if (!ms.buffer)
			break;
		ms.input = ms.buffer;
		if (ms.buffer)
			add_history(ms.buffer);
		tokenizer(&ms);
		if (parser(&ms, env))
			print_tester_value(&ms);
		free_tok(&ms);
	}
	free_env(env);
}
