#include "../src/chess.h"

static void	fill_tex(t_vars *vars, char *src, int i)
{
	int	j = 0;

	while (j < 14)
	{
		vars->tex->pawn->mat[i][j] = src[j];
		j++;
	}
	vars->tex->pawn->mat[i][j] = '\0';
}

void	ft_pawn(t_vars *vars)
{;
	fill_tex(vars, "     MMMM     ", 0);
	fill_tex(vars, "    MOOOOM    ", 1);
	fill_tex(vars, "    MOOOOM    ", 2);
	fill_tex(vars, "    MOOOOM    ", 3);
	fill_tex(vars, "     MMMM     ", 4);
	fill_tex(vars, "    MOOOOM    ", 5);
	fill_tex(vars, "     MMMM     ", 6);
	fill_tex(vars, "     MOOM     ", 7);
	fill_tex(vars, "     MOOM     ", 8);
	fill_tex(vars, "    MOOOOM    ", 9);
	fill_tex(vars, "   MMMMMMMM   ", 10);
	fill_tex(vars, "  MOOOOOOOOM  ", 11);
	fill_tex(vars, " MOOOOOOOOOOM ", 12);
	fill_tex(vars, " MMMMMMMMMMMM ", 13);
	fill_tex(vars, "MOOOOOOOOOOOOM", 14);
	fill_tex(vars, " MMMMMMMMMMMM ", 15);
}