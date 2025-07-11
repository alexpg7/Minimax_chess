#include "../src/chess.h"

static void	fill_tex(t_vars *vars, char *src, int i)
{
	int	j = 0;

	while (j < 11)
	{
		vars->tex->mouse->mat2[i][j] = src[j];
		j++;
	}
	vars->tex->mouse->mat2[i][j] = '\0';
}

void	ft_mouse(t_vars *vars)
{;
	fill_tex(vars, "M          ", 0);
	fill_tex(vars, "MM         ", 1);
	fill_tex(vars, "MOM        ", 2);
	fill_tex(vars, "MOOM       ", 3);
	fill_tex(vars, "MOOOM      ", 4);
	fill_tex(vars, "MOOOOM     ", 5);
	fill_tex(vars, "MOOOOOM    ", 6);
	fill_tex(vars, "MOOOOOOM   ", 7);
	fill_tex(vars, "MOOOOOOOM  ", 8);
	fill_tex(vars, "MOOOOOOOOM ", 9);
	fill_tex(vars, "MOOOOOMMMMM", 10);
	fill_tex(vars, "MOOMOOM    ", 11);
	fill_tex(vars, "MOM MOOM   ", 12);
	fill_tex(vars, "MM  MOOM   ", 13);
	fill_tex(vars, "     MOOM  ", 14);
	fill_tex(vars, "     MOOM  ", 15);
	fill_tex(vars, "      MOOM ", 16);
	fill_tex(vars, "      MOOM ", 17);
	fill_tex(vars, "       MM  ", 18);
}