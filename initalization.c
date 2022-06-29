/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:58:23 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/29 10:20:43 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief important: Associates fd 0 with infile
 * 
 * @param vars 
 */
void	init_all(t_vars *vars, int ac, char **av, char **env)
{
	vars->is_outfile = 1;
	vars->ac = ac;
	vars->av = av;
	vars->env = env;
	vars->last_cmd = (vars->ac - 2);
	conditions(vars);
	if (vars->is_outfile)
	{
		vars->outfile = open(vars->av[ac - 1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (vars->outfile == -1)
		{
			perror("open(outfile)");
			exit (-1);
		}
	}
}
