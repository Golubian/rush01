/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:34:40 by gachalif          #+#    #+#             */
/*   Updated: 2024/01/21 16:13:09 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (-1);
}

int	ft_check_input(char *input)
{
	int	i;

	if (ft_strlen(input) != 31)
		return (0);
	i = 0;
	while (i < 31)
	{
		if ((i % 2 == 0) && (input[i] < 49 || input[i] > 52))
			return (0);
		else if ((i % 2 == 1) && (input[i] != ' '))
			return (0);
		i++;
	}
	return (1);
}

void	ft_fill_grid(int **grid_view, char *input)
{
	int	i;
	int	h;

	i = 0;
	while (input[i])
	{
		if (i % 2 == 0)
		{
			h = i / 2;
			grid_view[h / 4][h % 4] = input[i] - 48;
		}
		i++;
	}
}

int	main(int argC, char **argV)
{
	int		**grid_view;
	int		**solution;

	if (argC != 2 || !ft_check_input(argV[1]))
		return (ft_error());
	grid_view = ft_generate_tab(4);
	if (!grid_view)
		return (ft_error());
	ft_fill_grid(grid_view, argV[1]);
	solution = ft_generate_solution(grid_view);
	if (!solution)
		return (ft_error());
	ft_write_grid(solution);
	ft_free_tab(grid_view, 4);
	ft_free_tab(solution, 4);
}
