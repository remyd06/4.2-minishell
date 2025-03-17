/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:25:19 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/17 01:12:02 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_env_to_array(t_env *list)
{
	char	**array;
	int		i;
	int		leng;

	i = 0;
	array = malloc((ft_lstsize_env(list) + 1) * sizeof(char*));
	if (array == NULL)
		return (NULL);
	while(list)
	{
		leng = ft_strlen(list->name) + ft_strlen(list->arg) + 2;
		array[i] = malloc(leng * sizeof(char));
		if (array[i] == NULL)
		{
			ft_free_deep(array);
			return (NULL);
		}
		ft_bzero(array[i], leng);
		ft_strlcat(array[i], list->name, leng);
		if (list->is_egal == true)
		{
			ft_strlcat(array[i], "=", leng);
			ft_strlcat(array[i], list->arg, leng);
		}
		i++;
		list = list->next;
	}
	array[i] = NULL;
	return (array);
}
