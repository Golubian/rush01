/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:27:53 by gachalif          #+#    #+#             */
/*   Updated: 2024/01/21 15:56:27 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <unistd.h>

int		c_grid(int **g, int **gv);
int		ft_strlen(char *str);
void	ft_write_grid(int **grid);
void	ft_all_comb_generation(int **all_comb, int nb_lc);
void	ft_free_tab(int **grid, int len);
int		**ft_generate_tab(int len);
int		**ft_generate_solution(int **grid_view);

#endif