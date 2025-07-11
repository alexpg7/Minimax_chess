#include "../src/chess.h"

static void	fill_tex(t_vars *vars, char *src, int i)
{
	int	j = 0;

	while (j < 14)
	{
		vars->tex->rook->mat[i][j] = src[j];
		j++;
	}
	vars->tex->rook->mat[i][j] = '\0';
}

void	ft_rook(t_vars *vars)
{;
	fill_tex(vars, "MMM  MMMM  MMM", 0);
	fill_tex(vars, "MOM  MOOM  MOM", 1);
	fill_tex(vars, "MOMMMMOOMMMMOM", 2);
	fill_tex(vars, "MOOOOOOOOOOOOM", 3);
	fill_tex(vars, "MOOOOOOOOOOOOM", 4);
	fill_tex(vars, " MMMMMMMMMMMM ", 5);
	fill_tex(vars, "  MOOOOOOOOM  ", 6);
	fill_tex(vars, "  MOOOOOOOOM  ", 7);
	fill_tex(vars, "  MOOOOOOOOM  ", 8);
	fill_tex(vars, "  MOOOOOOOOM  ", 9);
	fill_tex(vars, "  MOOOOOOOOM  ", 10);
	fill_tex(vars, " MOOOOOOOOOOM ", 11);
	fill_tex(vars, " MOOOOOOOOOOM ", 12);
	fill_tex(vars, "MMMMMMMMMMMMMM", 13);
	fill_tex(vars, "MOOOOOOOOOOOOM", 14);
	fill_tex(vars, " MMMMMMMMMMMM ", 15);
}