#include "chess.h"

void	pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + y * vars->line_length + x * vars->bits_per_pixel / 8;
	*(unsigned int *)dst = color;
}

int	color_mix(int color, int color2)
{
	unsigned int r1 = (color >> 16) & 0xFF;
    unsigned int g1 = (color >> 8) & 0xFF;
    unsigned int b1 = color & 0xFF;

    unsigned int r2 = (color2 >> 16) & 0xFF;
    unsigned int g2 = (color2 >> 8) & 0xFF;
    unsigned int b2 = color2 & 0xFF;

	if (color2 == 0)
		return (color);
	else
	{
		r1 = (2 * r1 + r2) / 3;
		g1 = (2 * g1 + g2) / 3;
		b1 = (2 * b1 + b2) / 3;
		return ((r1 << 16) | (g1 << 8) | b1);
	}
}

void	pixel_put2(t_vars *vars, int x, int y, int color)
{
	char	*dst;
	char	c;
	int		k = 0;

	c = vars->board2[8 * y / Y][8 * x / X];
	if (c == 'S')
		k = SC;
	if (c == 'A')
		k = AC;
	dst = vars->addr + y * vars->line_length + x * vars->bits_per_pixel / 8;
	*(unsigned int *)dst = color_mix(color, k);
}

int	ft_inmouse(int x, int y)
{
	if (x >= 0 && x <= 3 * MSIZE / 2 && y >= 0 && y <= MSIZE)
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