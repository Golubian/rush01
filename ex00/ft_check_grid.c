/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:17:26 by gachalif          #+#    #+#             */
/*   Updated: 2024/01/21 14:29:12 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_check_duplicates(int **g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g[0][i] == g[1][i] || g[0][i] == g[2][i] || g[0][i] == g[3][i])
			return (0);
		if (g[1][i] == g[2][i] || g[1][i] == g[3][i] || g[2][i] == g[3][i])
			return (0);
		i++;
	}
	return (1);
}

int	c_line(int *line, int line_view, int rev)
{
	int	max;
	int	seen;
	int	i;

	i = 0;
	max = 0;
	seen = 0;
	while (i < 4)
	{
		if ((line[i] > max && !rev) || (line[3 - i] > max && rev))
		{
			seen += 1;
			if (!rev)
				max = line[i];
			else
				max = line[3 - i];
		}
		i++;
	}
	return (line_view == seen);
}

int	c_col(int **g, int c_i, int c_view, int rev)
{
	int	max;
	int	seen;
	int	i;

	i = 0;
	max = 0;
	seen = 0;
	while (i < 4)
	{
		if ((g[i][c_i] > max && !rev) || (g[3 - i][c_i] > max && rev))
		{
			seen += 1;
			if (!rev)
				max = g[i][c_i];
			else
				max = g[3 - i][c_i];
		}
		i++;
	}
	return (c_view == seen);
}

int	c_grid(int **g, int **gv)
{
	int	i;

	if (!ft_check_duplicates(g))
		return (0);
	i = 0;
	while (i < 4)
	{
		if (!c_line(g[i], gv[2][i], 0) || !c_line(g[i], gv[3][i], 1))
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (!c_col(g, i, gv[0][i], 0) || !c_col(g, i, gv[1][i], 1))
			return (0);
		i++;
	}
	return (1);
}
