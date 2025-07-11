#include "chess.h"

static void	ft_fill(t_vars *vars, char *str, int j)
{
	int	i;

	for (i = 0; i < 8; i++)
	{
		vars->board2[j][i] = str[i];
	}
	vars->board[j][i] = '\0';
}

void	ft_blank(t_vars *vars)
{
	ft_fill(vars, "        ", 0);
	ft_fill(vars, "        ", 1);
	ft_fill(vars, "        ", 2);
	ft_fill(vars, "        ", 3);
	ft_fill(vars, "        ", 4);
	ft_fill(vars, "        ", 5);
	ft_fill(vars, "        ", 6);
	ft_fill(vars, "        ", 7);
}