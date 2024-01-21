/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_solution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:55:55 by gachalif          #+#    #+#             */
/*   Updated: 2024/01/21 16:11:01 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_free_tab(int **grid, int len)
{
	int	i;

	i = 0;
	if (i < len)
		free(grid[i++]);
	free(grid);
}

int	**ft_generate_tab(int len)
{
	int	i;
	int	**tab;

	tab = malloc(sizeof(int *) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i] = malloc(sizeof(int) * 5);
		if (!tab[i])
		{
			ft_free_tab(tab, i - 1);
			return (NULL);
		}
		i++;
	}
	return (tab);
}

void	ft_place_grid(int **grid, int **combs, int i)
{
	int	index;

	index = 0;
	while (index < 16)
	{
		grid[0][index % 4] = combs[i / 13824][index % 4];
		grid[1][index % 4] = combs[(i / 576) % 24][index % 4];
		grid[2][index % 4] = combs[(i / 24) % 24][index % 4];
		grid[3][index % 4] = combs[i % 24][index % 4];
		index++;
	}
}

int	**ft_generate_solution(int **grid_view)
{
	int	**combs;
	int	**grid;
	int	i;

	combs = ft_generate_tab(24);
	if (!combs)
		return (NULL);
	grid = ft_generate_tab(4);
	if (!grid)
		return (NULL);
	ft_all_comb_generation(combs, 4);
	i = 0;
	while (i < 331776)
	{
		ft_place_grid(grid, combs, i);
		if (c_grid(grid, grid_view))
		{
			ft_free_tab(combs, 24);
			return (grid);
		}
		i++;
	}
	return (NULL);
}
