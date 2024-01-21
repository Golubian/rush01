/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_comb_generation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:35:36 by segarand          #+#    #+#             */
/*   Updated: 2024/01/21 11:29:19 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_factorial(int n)
{
	if (n == 0 || n == 1)
		return (1);
	else
		return (n * ft_factorial(n -1));
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_copy(int **all_comb, int line, int nbcol)
{
	int	i;

	i = 0;
	while (i < nbcol)
	{
		all_comb[line][i] = all_comb[line - 1][i];
		i++;
	}
}

void	ft_modification(int **all_comb, int line, int nbcol, int begin)
{
	if (begin % 2 == 0)
	{
		ft_copy(all_comb, line, nbcol);
		ft_swap(&all_comb[line][2], &all_comb[line][3]);
	}
	if (begin % 2 == 1 && line != ft_factorial(nbcol))
	{
		ft_copy(all_comb, line, nbcol);
		ft_swap(&all_comb[line][1], &all_comb[line][2]);
	}
}

void	ft_all_comb_generation(int **all_comb, int nb_lc) // nb_lc va etre 4
{
	int	i;
	int	begin;

	i = 0;
	while (i < nb_lc)
	{
		all_comb[0][i] = i + 1;
		i++;
	}
	i = 0;
	begin = 0;
	while (i < ft_factorial(nb_lc))
	{
		while (begin < ft_factorial(nb_lc - 1))
		{
			i++;
			ft_modification(all_comb, i, nb_lc, begin);
			begin ++;
		}
		begin = 0;
		if (i != ft_factorial(nb_lc))
			ft_swap(&all_comb[i][0], &all_comb[i][all_comb[i][0]]);
	}
}

// int	main(void)
// {
// 	int	**all_comb;
// 	int	nombre;
// 	int	i;

// 	nombre = 4;
// 	all_comb = (int **) malloc(24 * sizeof (int *));
// 	i = 0;
// 	while (i < 24)
// 		all_comb[i++] = (int *)malloc(4 * sizeof (int));
// 	ft_all_comb_generation(all_comb, nombre);
// 	i = 0;
// 	while (i < 24)
// 	{
// 		printf("Valeur dans ligne[%d] = %d%d%d%d\n", i, all_comb[i][0],
// 			all_comb[i][1], all_comb[i][2], all_comb[i][3]);
// 		i++;
// 	}
// 	free(all_comb);
// 	return (0);
// }
