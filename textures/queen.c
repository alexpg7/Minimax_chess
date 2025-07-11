#include "../src/chess.h"

static void	fill_tex(t_vars *vars, char *src, int i)
{
	int	j = 0;

	while (j < 14)
	{
		vars->tex->queen->mat[i][j] = src[j];
		j++;
	}
	vars->tex->queen->mat[i][j] = '\0';
}

void	ft_queen(t_vars *vars)
{;
	fill_tex(vars, "     M  M     ", 0);
	fill_tex(vars, " M  MOMMOM  M ", 1);
	fill_tex(vars, "MOMMMMMMMMMMOM", 2);
	fill_tex(vars, " MMMMOMMOMMMM ", 3);
	fill_tex(vars, " MOMMOMMOMMOM ", 4);
	fill_tex(vars, " MOOMOMMOMOOM ", 5);
	fill_tex(vars, " MOOOOMMOOOOM ", 6);
	fill_tex(vars, " MOOOOOOOOOOM ", 7);
	fill_tex(vars, " MOOOOOOOOOOM ", 8);
	fill_tex(vars, " MOOOOOOOOOOM ", 9);
	fill_tex(vars, "  MOOOOOOOOM  ", 10);
	fill_tex(vars, "  MOOOOOOOOM  ", 11);
	fill_tex(vars, "  MOOOOOOOOM  ", 12);
	fill_tex(vars, " MMMMMMMMMMMM ", 13);
	fill_tex(vars, "MOOOOOOOOOOOOM", 14);
	fill_tex(vars, " MMMMMMMMMMMM ", 15);
}