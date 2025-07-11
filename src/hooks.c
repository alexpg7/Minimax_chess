#include "chess.h"

int	exit_chess(t_vars *vars, int ex)
{
	if (vars->mlx)
	{
		if (vars->img)
			mlx_destroy_image(vars->mlx, vars->img);
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(ex);
	return (0);
}

int	mouse_hook(int code, int x, int y, t_vars *vars)
{
	if (code == 1)
		ft_select(x, y, vars);
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	ft_putmouse(x, y, vars);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 5)
	{
		ft_printf("%s", vars->board[0]);
	}
	return (0);
}
