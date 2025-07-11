#include "../src/chess.h"

static void	fill_tex(t_vars *vars, char *src, int i)
{
	int	j = 0;

	while (j < 14)
	{
		vars->tex->king->mat[i][j] = src[j];
		j++;
	}
	vars->tex->king->mat[i][j] = '\0';
}

void	fill_king(int x, int y, t_vars *vars)
{
	int		i;
	int		j;
	char	c ;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			c = vars->board[j + y][i + x];
			if ((i == 0 && j == 0) || ft_lim(x + i) == 42 || ft_lim(y + j) == 42)
			{
				j++;
				continue ;// SHOULD INCORPORATE A RED TILE WITH DANGEROUS TILES
			}
			if (c == ' ' || (c <= 'Z' && c >= 'A'))
			{
				vars->board2[j + y][i + x] = 'A';
				print_square(100 * (i + x), 100 * (j + y), vars);
			}
			j++;
		}
		i++;
	}
}

void	ft_king(t_vars *vars)
{;
	fill_tex(vars, "      MM      ", 0);
	fill_tex(vars, "     MMMM     ", 1);
	fill_tex(vars, "      MM      ", 2);
	fill_tex(vars, "  MMM MM MMM  ", 3);
	fill_tex(vars, " MOOOMMMMOOOM ", 4);
	fill_tex(vars, "MOOOOOMMOOOOOM", 5);
	fill_tex(vars, "MOOOOOMMOOOOOM", 6);
	fill_tex(vars, "MOOOOOMMOOOOOM", 7);
	fill_tex(vars, "MOOOMMMMMMOOOM", 8);
	fill_tex(vars, "MMMMOOMMOOMMMM", 9);
	fill_tex(vars, " MOOOOMMOOOOM ", 10);
	fill_tex(vars, " MMMMMMMMMMMM ", 11);
	fill_tex(vars, "  MOOOOOOOOM  ", 12);
	fill_tex(vars, " MMMMMMMMMMMM ", 13);
	fill_tex(vars, "MOOOOOOOOOOOOM", 14);
	fill_tex(vars, " MMMMMMMMMMMM ", 15);
}