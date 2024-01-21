/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:34:40 by gachalif          #+#    #+#             */
/*   Updated: 2024/01/21 15:37:55 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	int		i;
	char	int_to_char;

	if (argC != 2 || !ft_check_input(argV[1]))
		return (ft_error());
	grid_view = ft_generate_tab(4);
	if (!grid_view)
		return (ft_error());
	ft_fill_grid(grid_view, argV[1]);
	solution = ft_generate_solution(grid_view);
	if (!solution)
		return (ft_error());
	i = 0;
	while (i < 16)
	{
		int_to_char = solution[i / 4][i % 4] + 48;
		write(1, &int_to_char, 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}
