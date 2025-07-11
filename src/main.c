#include "chess.h"

void	ft_initmlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!(vars->mlx))
	{
		perror("mlx init");
		exit_chess(vars, 1);
	}
	vars->win = mlx_new_window(vars->mlx, X, Y, "Minimax Chess");
	vars->img = mlx_new_image(vars->mlx, X, Y);
	if (!(vars->win) || !(vars->img))
	{
		perror("mlx error");
		exit_chess(vars, 1);
	}
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	if (!(vars->addr) || !(vars->bits_per_pixel) || !(vars->line_length))
	{
		perror("mlx address get");
		exit_chess(vars, 1);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	print_full_board(vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_hook(vars->win, 17, 0L, exit_chess, vars);
	mlx_hook(vars->win, 6, 1L<<6, mouse_move, vars);
	mlx_mouse_hide(vars->mlx, vars->win); //PRODUCES LEAKS
	printf("Click the cross to exit the program.\n\n");
	mlx_loop(vars->mlx);
}

static void	ft_fill(t_vars *vars, char *str, int j)
{
	int	i;

	for (i = 0; i < 8; i++)
	{
		vars->board[j][i] = str[i];
	}
	vars->board[j][i] = '\0';
}

void	ft_init(t_vars *vars)
{
	// YOU ARE WHITE (SHOULD CHANGE IT AT SOME POINT)
	ft_fill(vars, "RHBQKBHR", 0);
	ft_fill(vars, "PPPPPPPP", 1);
	ft_fill(vars, "        ", 2);
	ft_fill(vars, "        ", 3);
	ft_fill(vars, "        ", 4);
	ft_fill(vars, "        ", 5);
	ft_fill(vars, "pppppppp", 6);
	ft_fill(vars, "rhbqkbhr", 7);
	ft_blank(vars);
	ft_rook(vars);
	ft_horse(vars);
	ft_bishop(vars);
	ft_queen(vars);
	ft_king(vars);
	ft_pawn(vars);
	ft_mouse(vars);
}

int	main(void)
{
	t_vars	vars;
	t_tex	tex;
	t_obj	rook;
	t_obj	horse;
	t_obj	bishop;
	t_obj	queen;
	t_obj	king;
	t_obj	pawn;
	t_obj	mouse;

	vars.lastx = 0;
	vars.lasty = 0;
	vars.tex = &tex;
	vars.tex->rook = &rook;
	vars.tex->horse = &horse;
	vars.tex->bishop = &bishop;
	vars.tex->queen = &queen;
	vars.tex->king = &king;
	vars.tex->pawn = &pawn;
	vars.tex->mouse = &mouse;
	ft_init(&vars); //more things, ask parameters, etc.
	ft_initmlx(&vars);
	return (0);
}
