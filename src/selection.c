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

int	ft_isallowed(char c)
{
	if (c == 'A')//more types of tiles A: allowed movement, K: kill
	{
		return (1);
	}
	return (0);
}

void	fill_available(int i, int j, t_vars *vars)
{
	char	c = vars->board[j][i];

	if (c == 'P' || c == 'p')
		fill_pawn(i, j, vars);
	if (c == 'K' || c == 'k')
		fill_king(i, j, vars);
}

void	ft_select(int x, int y, t_vars *vars)
{
	int i = 8 * x / X;
	int j = 8 * y / Y;

	if (vars->mode == 'f' && vars->board[j][i] != ' ')//occuppied by lowercase (if im white)
	{
		vars->sx = i;
		vars->sy = j;
		vars->mode = 's';
		vars->board2[j][i] = 'S';
		print_square(100 * i, 100 * j, vars);

		fill_available(i, j, vars);
	}
	else if (vars->mode == 's')
	{
		if (ft_isallowed(vars->board2[j][i]))
		{
			ft_blank(vars);
			vars->board[j][i] = vars->board[vars->sy][vars->sx];
			vars->board[vars->sy][vars->sx] = ' ';
			if (vars->board[j][i] == 'p' && j == 0)
				vars->board[j][i] = 'q';
			vars->mode = 'f'; //should be wait when we have the AI
			print_full_board(vars);
		}
		else
		{
			ft_blank(vars); //should select the desired tile?
			vars->mode = 'f';
			print_full_board(vars);
		}
	}
	ft_putmouse(x, y, vars);
	/*for (int k = 0; k < 8; k++)
		ft_printf("%s\n", vars->board2[k]);*/
}