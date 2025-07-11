#include "chess.h"

char	def_object(int px, int py, char c, t_vars *vars)
{
	if (c == 'R' || c == 'r')
		return (vars->tex->rook->mat[py][px]);
	if (c == 'H' || c == 'h')
		return (vars->tex->horse->mat[py][px]);
	if (c == 'B' || c == 'b')
		return (vars->tex->bishop->mat[py][px]);
	if (c == 'Q' || c == 'q')
		return (vars->tex->queen->mat[py][px]);
	if (c == 'K' || c == 'k')
		return (vars->tex->king->mat[py][px]);
	if (c == 'P' || c == 'p')
		return (vars->tex->pawn->mat[py][px]);
	return (' ');
}

void	print_object(int x, int y, t_vars *vars, char o)
{
	int		px = 160 * x / X % 20;
	int		py = 160 * y / Y % 20;
	int		cx = 8 * x / X;
	int		cy = 8 * y / Y;
	int		c1;
	int		c2;
	char	c;

	if (px < 3 || px > 16 || py < 2 || py > 17)
		c = ' ';
	else
		c = def_object(px - 3, py - 2, o, vars);
	if (o <= 'Z' && o >= 'A')
	{
		c1 = B1;
		c2 = B2;
	}
	else if (o <= 'z' && o >= 'a')
	{
		c1 = W1;
		c2 = W2;
	}
	if (c == 'M')
		pixel_put(vars, x, y, c1);
	else if (c == 'O')
		pixel_put(vars, x, y, c2);
	else
	{
		if ((cx + cy) % 2 == 0)
			pixel_put(vars, x, y, WHITE);
		else
			pixel_put(vars, x, y, BLACK);
	}
}

void	print_board(int x, int y, t_vars *vars)
{
	int	cx;
	int	cy;

	cx = 8 * x / X;
	cy = 8 * y / Y;
	if (vars->board[cy][cx] != ' ')
		print_object(x, y, vars, vars->board[cy][cx]);
	else
	{
		if ((cx + cy) % 2 == 0)
			pixel_put(vars, x, y, WHITE);
		else
			pixel_put(vars, x, y, BLACK);
	}
}

void	print_full_board(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < X)
	{
		j = 0;
		while (j < Y)
		{
			print_board(i, j, vars);
			j++;
		}
		i++;
	}
}