/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:09:34 by dkovalen          #+#    #+#             */
/*   Updated: 2017/01/27 10:44:43 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pizza.h"

int		**expand_rez(int **rez, int len)
{
	int		i;
	int		j;
	int		**ret;

	ret = (int **)malloc(sizeof(int *) * len);
	i = 0;
	while (i < len)
		ret[i++] = (int *)malloc(sizeof(int) * 4);
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		ret[i] = (int *)malloc(sizeof(int) * 4);
		while (j < 4)
		{
			ret[i][j] = rez[i][j];
			j++;
		}
		free(rez[i]);
		i++;
	}
	free(rez);
	return (ret);
}
