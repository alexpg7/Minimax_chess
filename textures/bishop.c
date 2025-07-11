#include "../src/chess.h"

static void	fill_tex(t_vars *vars, char *src, int i)
{
	int	j = 0;

	while (j < 14)
	{
		vars->tex->bishop->mat[i][j] = src[j];
		j++;
	}
	vars->tex->bishop->mat[i][j] = '\0';
}

void	ft_bishop(t_vars *vars)
{;
	fill_tex(vars, "      MM      ", 0);
	fill_tex(vars, "    MMOOMM    ", 1);
	fill_tex(vars, "   MOOOOOOM   ", 2);
	fill_tex(vars, "  MOOOMMOOOM  ", 3);
	fill_tex(vars, " MOOOOMMOOOOM ", 4);
	fill_tex(vars, " MOOMMMMMMOOM ", 5);
	fill_tex(vars, "MOOOMMMMMMOOOM", 6);
	fill_tex(vars, "MOOOOOMMOOOOOM", 7);
	fill_tex(vars, "MOOOOOMMOOOOOM", 8);
	fill_tex(vars, " MOOOOMMOOOOM ", 9);
	fill_tex(vars, " MOOOOMMOOOOM ", 10);
	fill_tex(vars, "  MOOOMMOOOM  ", 11);
	fill_tex(vars, "   MOOOOOOM   ", 12);
	fill_tex(vars, " MMMMMMMMMMMM ", 13);
	fill_tex(vars, "MOOOOOOOOOOOOM", 14);
	fill_tex(vars, " MMMMMMMMMMMM ", 15);
}