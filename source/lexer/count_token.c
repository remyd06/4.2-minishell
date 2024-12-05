/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:28:04 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/05 13:13:36 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_token(char *str)
{
	int		countword;
	int		i;

	countword = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i])
	{	
		if ((str[i] ==  '>' || str[i] == '<') && str[i + 1] == str[i])
		{
			countword++;
			i += 2;
		}
		if (ft_ismeta(str[i]))
			countword++;
		if (ft_isspace)
			countword++;
		while (ft_isspace)
			i++;
		if (ft_isprint && !ft_ismeta && (str[i] !=  '>' || str[i] != '<'))
			countword++;
		while (ft_isprint && !ft_ismeta && (str[i] !=  '>' || str[i] != '<'))
			i++;
	}
	return (i);
	
}
