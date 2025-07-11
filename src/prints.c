#include "chess.h"

void	pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + y * vars->line_length + x * vars->bits_per_pixel / 8;
	*(unsigned int *)dst = color;
}

int	ft_inmouse(int x, int y)
{
	if (x >= 0 && x <= MSIZE && y >= 0 && y <= MSIZE)
		return (1);
	else
		return (0);
}

int	print_mouse(t_vars *vars, int x, int y, int x_0, int y_0)
{
	int	px = 19 * x / MSIZE;
	int	py = 19 * y / MSIZE;

	if (px > 11 || px < 0 || py > 18 || py < 0)
		return (0);
	else
	{
		if (vars->tex->mouse->mat2[py][px] == 'O')
			pixel_put(vars, x + x_0, y + y_0, MC1);
		else if (vars->tex->mouse->mat2[py][px] == 'M')
			pixel_put(vars, x + x_0, y + y_0, MC2);
		else
			return (0);
	}
	return (1);
}

void	ft_putmouse(int x, int y, t_vars *vars)
{
	int	i;
	int	lx;
	int	j;
	int	ly;

	i = 0;
	lx = vars->lastx;
	ly = vars->lasty;
	while (i < X)
	{
		j = 0;
		while (j < Y)
		{
			if (ft_inmouse(i - lx, j - ly))
				print_board(i, j, vars);
			if (ft_inmouse(i - x, j - y))
			{
				if (!print_mouse(vars, i - x, j - y, x, y))
					print_board(i, j, vars);
			}
			j++;
		}
		i++;
	}
	vars->lastx = x;
	vars->lasty = y;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}