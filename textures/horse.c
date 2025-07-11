#include "../src/chess.h"

static void	fill_tex(t_vars *vars, char *src, int i)
{
	int	j = 0;

	while (j < 14)
	{
		vars->tex->horse->mat[i][j] = src[j];
		j++;
	}
	vars->tex->horse->mat[i][j] = '\0';
}

void	ft_horse(t_vars *vars)
{;
	fill_tex(vars, "     M        ", 0);
	fill_tex(vars, "    MOMM      ", 1);
	fill_tex(vars, "   MOOOOMM    ", 2);
	fill_tex(vars, "  MOMOOOOOM   ", 3);
	fill_tex(vars, " MOOOOOOOOOM  ", 4);
	fill_tex(vars, "MOOOOOMOOOOOM ", 5);
	fill_tex(vars, "MOOOOMMOOOOOM ", 6);
	fill_tex(vars, "MOOMM MOOOOOM ", 7);
	fill_tex(vars, " MM  MOOOOOOM ", 8);
	fill_tex(vars, "    MOOOOOOM  ", 9);
	fill_tex(vars, "   MOOOOOOOM  ", 10);
	fill_tex(vars, "  MOOOOOOOOM  ", 11);
	fill_tex(vars, " MOOOOOOOOOOM ", 12);
	fill_tex(vars, "MMMMMMMMMMMMMM", 13);
	fill_tex(vars, "MOOOOOOOOOOOOM", 14);
	fill_tex(vars, " MMMMMMMMMMMM ", 15);
}