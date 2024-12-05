/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:32:56 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/05 14:59:59 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(void)
{
	main_interface_print();
}

int	main(void)
{
	t_ms	ms;
	char	*buffer;

	init_shell();
	while (1)
	{
		buffer = readline(YEL"MINISHELL> "ENDCL);
			if (!buffer)
				return (0);
		ms.input = buffer;
		if (buffer)
			add_history(buffer);
		printf("%d\n", count_token(ms.input));
	}
}
