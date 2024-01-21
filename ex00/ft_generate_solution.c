/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_solution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:55:55 by gachalif          #+#    #+#             */
/*   Updated: 2024/01/21 14:26:03 by gachalif         ###   ########.fr       */
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
	grid[0] = combs[i / 13824];
	grid[1] = combs[(i / 576) % 24];
	grid[2] = combs[(i / 24) % 24];
	grid[3] = combs[i % 24];
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
			return (grid);
		i++;
	}
	return (NULL);
}
